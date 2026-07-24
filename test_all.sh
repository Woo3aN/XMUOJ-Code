#!/bin/bash
# ============================================
#  XMUOJ 批量本地测试脚本
#  遍历所有题目，编译 + 跑样例，输出 AC/WA
#  用法: ./test_all.sh
# ============================================

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
PASS=0
FAIL=0
SKIP=0
RESULTS=()

# 颜色定义
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m'
BOLD='\033[1m'

# 收集所有 .xmuoj.json 路径
JSON_FILES=()
while IFS= read -r line; do
    JSON_FILES+=("$line")
done < <(find "$ROOT_DIR"/contest-* -maxdepth 2 -name ".xmuoj.json" 2>/dev/null | sort)

TOTAL=${#JSON_FILES[@]}
CURRENT=0

echo -e "${BOLD}========================================${NC}"
echo -e "${BOLD}  XMUOJ 批量本地测试  (共 ${TOTAL} 题)${NC}"
echo -e "${BOLD}========================================${NC}"
echo ""

for XMUOJ_JSON in "${JSON_FILES[@]}"; do
    PROB_DIR="$(dirname "$XMUOJ_JSON")"
    PROB_NAME="$(basename "$PROB_DIR")"
    CURRENT=$((CURRENT + 1))

    # 读取 sourceFile
    SOURCE_FILE=$(grep -o '"sourceFile"[[:space:]]*:[[:space:]]*"[^"]*"' "$XMUOJ_JSON" | head -1 | sed 's/.*"\([^"]*\)"$/\1/')
    [ -z "$SOURCE_FILE" ] && SOURCE_FILE="main.cpp"

    SRC_PATH="$PROB_DIR/$SOURCE_FILE"
    SAMPLES_DIR="$PROB_DIR/samples"
    BUILD_DIR="$PROB_DIR/.xmuoj-build"
    EXE_PATH="$BUILD_DIR/test-run.exe"

    printf "${CYAN}[%02d/%02d]${NC} %-30s " "$CURRENT" "$TOTAL" "$PROB_NAME"

    # 检查源文件
    if [ ! -f "$SRC_PATH" ]; then
        echo -e "${RED}✗ 源文件不存在: $SOURCE_FILE${NC}"
        RESULTS+=("${RED}✗${NC} $PROB_NAME — 源文件缺失")
        SKIP=$((SKIP + 1))
        continue
    fi

    # 检查是否为空文件
    if [ ! -s "$SRC_PATH" ]; then
        echo -e "${YELLOW}⚠  空文件，未完成${NC}"
        RESULTS+=("${YELLOW}⚠${NC}  $PROB_NAME — 空文件/未完成")
        SKIP=$((SKIP + 1))
        continue
    fi

    # 编译
    mkdir -p "$BUILD_DIR"
    EXT="${SOURCE_FILE##*.}"
    if [ "$EXT" = "c" ]; then
        COMPILER="gcc"
        CFLAGS="-O2"
    else
        COMPILER="g++"
        CFLAGS="-O2 -std=c++17"
    fi

    COMPILE_ERR="$BUILD_DIR/compile-err.txt"
    if ! $COMPILER "$SRC_PATH" -o "$EXE_PATH" $CFLAGS -mconsole 2>"$COMPILE_ERR"; then
        # 判断是否为缺少 main 函数导致的链接错误
        if grep -q "undefined reference to .WinMain\|undefined reference to .main" "$COMPILE_ERR" 2>/dev/null; then
            echo -e "${YELLOW}⚠  缺少 main()，需在 XMUOJ 平台评测${NC}"
            RESULTS+=("${YELLOW}⚠${NC}  $PROB_NAME — 需平台评测（无main）")
        else
            echo -e "${RED}✗ 编译失败${NC}"
            RESULTS+=("${RED}✗${NC} $PROB_NAME — 编译失败")
            FAIL=$((FAIL + 1))
        fi
        SKIP=$((SKIP + 1))
        continue
    fi

    # 跑样例
    SAMPLE_COUNT=0
    ALL_PASS=true
    for SAMPLE_IN in "$SAMPLES_DIR"/*.in; do
        [ -f "$SAMPLE_IN" ] || continue
        SAMPLE_COUNT=$((SAMPLE_COUNT + 1))

        BASE="${SAMPLE_IN%.in}"
        SAMPLE_OUT="${BASE}.out"

        ACTUAL_OUT="$BUILD_DIR/out-$(basename "$SAMPLE_IN" .in).txt"
        "$EXE_PATH" < "$SAMPLE_IN" > "$ACTUAL_OUT" 2>&1 || true

        if [ -f "$SAMPLE_OUT" ]; then
            if ! diff -q -w -B "$ACTUAL_OUT" "$SAMPLE_OUT" > /dev/null 2>&1; then
                ALL_PASS=false
            fi
        fi
    done

    if [ "$SAMPLE_COUNT" -eq 0 ]; then
        echo -e "${YELLOW}⚠  无样例数据${NC}"
        SKIP=$((SKIP + 1))
        RESULTS+=("${YELLOW}⚠${NC}  $PROB_NAME — 无样例")
    elif $ALL_PASS; then
        echo -e "${GREEN}✓ AC  (${SAMPLE_COUNT} 组样例)${NC}"
        PASS=$((PASS + 1))
        RESULTS+=("${GREEN}✓${NC}  $PROB_NAME ${GREEN}AC${NC}")
    else
        echo -e "${RED}✗ WA  (${SAMPLE_COUNT} 组样例中失败)${NC}"
        FAIL=$((FAIL + 1))
        RESULTS+=("${RED}✗${NC} $PROB_NAME ${RED}WA${NC}")
        # 显示具体差异
        for SAMPLE_IN in "$SAMPLES_DIR"/*.in; do
            [ -f "$SAMPLE_IN" ] || continue
            SAMP_BASE="${SAMPLE_IN%.in}"
            SAMPLE_OUT="${SAMP_BASE}.out"
            [ -f "$SAMPLE_OUT" ] || continue
            FILE_NUM=$(basename "$SAMPLE_IN" .in)
            ACTUAL_OUT="$BUILD_DIR/out-${FILE_NUM}.txt"
            if ! diff -q -w -B "$ACTUAL_OUT" "$SAMPLE_OUT" > /dev/null 2>&1; then
                echo -e "  ${RED}样例 #${FILE_NUM}:${NC}"
                echo -e "    ${BOLD}输入:${NC}"
                while IFS= read -r input_line; do echo "      $input_line"; done < "$SAMPLE_IN"
                echo -e "    ${BOLD}期望输出:${NC}"
                while IFS= read -r expect_line; do echo "      $expect_line"; done < "$SAMPLE_OUT"
                echo -e "    ${BOLD}实际输出:${NC}"
                while IFS= read -r actual_line; do echo "      $actual_line"; done < "$ACTUAL_OUT"
                echo ""
            fi
        done
    fi
done

echo ""
echo -e "${BOLD}========================================${NC}"
echo -e "${BOLD}  测试结果汇总${NC}"
echo -e "${BOLD}========================================${NC}"
echo -e "总计: $TOTAL   ${GREEN}AC: $PASS${NC}   ${RED}WA/编译失败: $FAIL${NC}   跳过: $SKIP"
echo ""

if [ "$FAIL" -gt 0 ]; then
    echo -e "${RED}  ✗ $FAIL 个题目未通过${NC}"
    echo ""
fi
if [ "$PASS" -eq "$TOTAL" ] 2>/dev/null && [ "$TOTAL" -gt 0 ]; then
    echo -e "${GREEN}${BOLD}  🎉 全部通过！${NC}"
    echo ""
fi

# 列出所有结果
echo -e "${BOLD}详细结果:${NC}"
for result in "${RESULTS[@]}"; do
    echo -e "  $result"
done
