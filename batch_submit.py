#!/usr/bin/env python3
"""
XMUOJ 批量提交评测脚本
- 遍历 contest-362 下所有题目，自动提交代码
- 支持跳过已 AC 的题目（需要读取上次提交记录）
- 每道题提交间隔 2 秒，避免请求过快
"""

import os
import sys
import json
import time

# Windows UTF-8 编码修复
if sys.platform == "win32":
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass
import re
import requests
from pathlib import Path
from getpass import getpass

# ============================================================
# 配置
# ============================================================
BASE_URL = "http://xmuoj.com"
CONTEST_DIR = Path(__file__).parent / "contest-362"  # 实验目录
INTERVAL = 0.3  # 每道题提交间隔（秒）

# ============================================================
# 工具函数
# ============================================================

def login(session: requests.Session):
    """登录 XMUOJ，获取 session cookie"""
    print("=" * 50)
    print("  XMUOJ 登录")
    print("=" * 50)
    username = input("用户名: ").strip()
    password = getpass("密码: ")

    # 1. 先获取 CSRF cookie（Django）
    resp = session.get(f"{BASE_URL}/api/login")
    # 2. 登录
    resp = session.post(
        f"{BASE_URL}/api/login",
        json={"username": username, "password": password},
        headers={
            "Content-Type": "application/json",
            "X-CSRFToken": session.cookies.get("csrftoken", ""),
            "Referer": f"{BASE_URL}/login",
        },
    )
    data = resp.json()
    if data.get("error"):
        print(f"\n❌ 登录失败: {data.get('data', data['error'])}")
        return False
    print(f"\n✅ 登录成功: {data.get('data', {}).get('user', '')}")
    return True


def scan_problems(contest_dir: Path) -> list[dict]:
    """扫描所有题目目录，读取 .xmuoj.json 和源代码"""
    problems = []
    if not contest_dir.exists():
        print(f"❌ 目录不存在: {contest_dir}")
        return problems

    for problem_dir in sorted(contest_dir.iterdir()):
        if not problem_dir.is_dir():
            continue
        meta_file = problem_dir / ".xmuoj.json"
        if not meta_file.exists():
            continue

        with open(meta_file, "r", encoding="utf-8") as f:
            meta = json.load(f)

        source_file = problem_dir / meta.get("sourceFile", "main.cpp")
        if not source_file.exists():
            print(f"⚠️  {meta['displayId']} {meta['title']} — 源文件不存在，跳过")
            continue

        with open(source_file, "r", encoding="utf-8") as f:
            code = f.read()

        if not code.strip():
            print(f"⚠️  {meta['displayId']} {meta['title']} — 代码为空，跳过")
            continue

        problems.append({
            "dir": problem_dir,
            "meta": meta,
            "code": code,
            "source_file": source_file,
        })
    return problems


def submit_one(session: requests.Session, problem: dict, contest_password: str | None = None):
    """提交一道题目"""
    meta = problem["meta"]
    display_id = meta["displayId"]
    title = meta["title"]
    problem_id = meta["problemId"]
    contest_id = meta.get("contestId")
    language = meta.get("language", "C++")
    code = problem["code"]

    payload = {
        "problem_id": problem_id,
        "contest_id": contest_id,
        "language": language,
        "code": code,
    }
    if contest_password:
        payload["contest_password"] = contest_password

    try:
        resp = session.post(
            f"{BASE_URL}/api/plugin/submission",
            json=payload,
            headers={
                "Content-Type": "application/json",
                "X-CSRFToken": session.cookies.get("csrftoken", ""),
                "Referer": f"{BASE_URL}/problem/{problem_id}",
            },
        )
        data = resp.json()
        if data.get("error"):
            return {"ok": False, "error": data.get("data", data["error"])}
        submission = data.get("data", data)
        submission_id = submission.get("submission_id", "?")
        return {"ok": True, "submission_id": submission_id}
    except requests.RequestException as e:
        return {"ok": False, "error": str(e)}


def wait_for_result(session: requests.Session, submission_id) -> dict | None:
    """等待判题结果"""
    max_wait = 30  # 最多等30秒
    for i in range(max_wait):
        time.sleep(1)
        try:
            resp = session.get(
                f"{BASE_URL}/api/plugin/submission?submission_id={submission_id}"
            )
            data = resp.json()
            if data.get("error"):
                return None
            result = data.get("data", data)
            # 如果结果不再是 pending/compiling/running，说明结束了
            label = result.get("result_label", "")
            if label and label not in ("Pending", "Compiling", "Running", "Waiting"):
                return result
        except Exception:
            pass
    return None


def main():
    print()
    print("╔══════════════════════════════════════════════════╗")
    print("║       XMUOJ 批量提交评测工具                     ║")
    print("╚══════════════════════════════════════════════════╝")
    print()

    # 扫描题目
    problems = scan_problems(CONTEST_DIR)
    if not problems:
        print("❌ 没有找到任何题目")
        return

    print(f"📋 共发现 {len(problems)} 道题目：")
    for p in problems:
        print(f"    [{p['meta']['displayId']}] {p['meta']['title']} "
              f"(problem_id={p['meta']['problemId']})")
    print()

    # 询问
    ans = input(f"是否对这 {len(problems)} 道题全部提交？[y/N] ").strip().lower()
    if ans != "y":
        # 选择范围
        print("\n输入要提交的题号范围（如 1-10），或直接回车取消:")
        print("（题号是上面列表的顺序号，从 1 开始）")
        r = input("范围: ").strip()
        if not r:
            print("已取消")
            return
        try:
            if "-" in r:
                start, end = r.split("-", 1)
                problems = problems[int(start.strip()) - 1 : int(end.strip())]
            else:
                idx = int(r)
                problems = [problems[idx - 1]]
        except (ValueError, IndexError):
            print("❌ 无效范围")
            return
        print(f"已选择 {len(problems)} 道题")

    # 检查是否需要密码
    contest_password = None
    # 如果需要密码，先尝试无密码获取题目信息
    pwd_ans = input("\n实验是否需要密码？[y/N] ").strip().lower()
    if pwd_ans == "y":
        contest_password = getpass("实验密码: ")

    # 登录
    session = requests.Session()
    session.headers.update({"User-Agent": "Mozilla/5.0 (compatible; XMUOJ-BatchSubmit/1.0)"})
    if not login(session):
        return

    # 逐题提交（极速模式：只提交不等结果）
    print()
    print("=" * 50)
    print("  批量提交中（极速模式）")
    print("=" * 50)
    print()

    submissions = []  # { display_id, title, submission_id }
    errors = []
    for i, problem in enumerate(problems):
        display_id = problem["meta"]["displayId"]
        title = problem["meta"]["title"]
        result = submit_one(session, problem, contest_password)
        if not result["ok"]:
            print(f"  [{i+1:2d}/{len(problems)}] {display_id:12s} ❌ {result['error']}")
            errors.append({"display_id": display_id, "title": title, "error": result["error"]})
        else:
            print(f"  [{i+1:2d}/{len(problems)}] {display_id:12s} ✅ 已提交 #{result['submission_id']}")
            submissions.append({"display_id": display_id, "title": title, "submission_id": result["submission_id"]})
        time.sleep(INTERVAL)

    # 等待所有结果
    if submissions:
        print()
        print(f"⏳ 等待 {len(submissions)} 道题的判题结果...")
        results = []
        for i, sub in enumerate(submissions):
            print(f"  [{i+1:2d}/{len(submissions)}] {sub['display_id']:12s} ... ", end="", flush=True)
            final = wait_for_result(session, sub["submission_id"])
            if final:
                label = final.get("result_label", "?")
                icon = "✅" if label == "Accepted" else "❌"
                print(f"{icon} {label}")
                results.append({**sub, "result": label})
            else:
                print("⏳ 超时（可在网站查看）")
                results.append({**sub, "result": "?"})
            time.sleep(0.2)

    # 汇总
    all_results = results + [{"display_id": e["display_id"], "title": e["title"], "result": e["error"]} for e in errors]
    print()
    print("=" * 50)
    print("  提交结果汇总")
    print("=" * 50)
    ac_count = sum(1 for r in all_results if r.get("result") == "Accepted")
    for r in all_results:
        icon = "✅" if r.get("result") == "Accepted" else ("❌" if "result" not in r or r.get("error") else "⏳")
        if r.get("error"):
            icon = "❌"
        detail = r.get("result") or r.get("error", "?")
        print(f"  {icon} [{r['display_id']}] {r['title']} — {detail}")
    print(f"\n  总计: {len(all_results)} 题 | AC: {ac_count} | 非 AC: {len(all_results) - ac_count}")


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n⚠️  用户中断")
        sys.exit(1)
