"""修复 XMUOJ 题目进度 —— 批量写入 AC 状态"""
import sqlite3, json, os

DB = r"C:\Users\Administrator\AppData\Roaming\Code\User\globalStorage\state.vscdb"
CONTEST = r"D:\vscode c++\contest-362"
SCOPE = r"D:\vscode c++"

# 43 AC + 1 WA + 1 未提交
ac_set = {
    'LinK01','LinK02','LinK03','LinK04','LinK05','LinK09','LinK10',
    'LinK13','LinK14','LinK14.5','LinK15','LinK16','LinK19','LinK21',
    'LinK27','LinK30','LinK31','LinK38','LinK39','LinK43','LinK44','LinK45',
    'LinK46','LinK47','LinK48','LinK51','LinK52','LinK53','LinK57','LinK62',
    'LinK63','LinK64','LinK65','LinK66','LinK67','LinK68','LinK69','LinK70',
    'LinK71','LinK72','LinK73','LinK75','LinK76',
}

# 读取所有题目的元数据
problems = {}
for d in sorted(os.listdir(CONTEST)):
    meta_path = os.path.join(CONTEST, d, ".xmuoj.json")
    if os.path.exists(meta_path):
        with open(meta_path, "r", encoding="utf-8") as f:
            meta = json.load(f)
            problems[str(meta["problemId"])] = meta

print(f"找到 {len(problems)} 道题")

# 读取现有进度
db = sqlite3.connect(DB)
row = db.execute("SELECT value FROM ItemTable WHERE key = 'xmuoj.xmuoj-vscode'").fetchone()
data = json.loads(row[0])
progress = data.get("xmuoj.problemProgress", {})

# 更新每道题
for pid, meta in problems.items():
    display_id = meta["displayId"]
    is_ac = display_id in ac_set
    key = f"http://xmuoj.com::362::{pid}::{SCOPE}"

    current = progress.get(key, {})
    progress[key] = {
        **current,
        "baseUrl": "http://xmuoj.com",
        "problemId": meta["problemId"],
        "displayId": display_id,
        "title": meta["title"],
        "contestId": 362,
        "contestTitle": meta.get("contestTitle", ""),
        "progressScope": SCOPE,
        "updatedAt": "2026-07-24T04:50:00.000Z",
        "workspaceCreated": True,
        "language": meta.get("language", "C++"),
        "sourceFile": "main.cpp",
        "lastSubmissionLabel": "Accepted" if is_ac else ("Wrong Answer" if display_id == "LinK20" else ""),
        "accepted": is_ac,
    }

data["xmuoj.problemProgress"] = progress
json_str = json.dumps(data, ensure_ascii=False)
db.execute("UPDATE ItemTable SET value = ? WHERE key = 'xmuoj.xmuoj-vscode'", (json_str,))
db.commit()
db.close()

# 验证
db2 = sqlite3.connect(DB)
row2 = db2.execute("SELECT value FROM ItemTable WHERE key = 'xmuoj.xmuoj-vscode'").fetchone()
data2 = json.loads(row2[0])
progress2 = data2.get("xmuoj.problemProgress", {})

ac_count = 0
for k, v in progress2.items():
    if SCOPE in k and v.get("accepted"):
        ac_count += 1

print(f"已更新，{ac_count} 道 AC 写入成功")
db2.close()
