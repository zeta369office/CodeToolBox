#!/bin/bash

# --- 設定顏色輸出 (讓畫面更好看) ---
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== CodeToolBox (CTB) Build System ===${NC}"

# 1. 執行 Python 生成器，同步 JSON 到 data.h
echo -e "${YELLOW}[1/3] 同步數據中... (Running DevMode.py)${NC}"
python3 DevMode.py
if [ $? -ne 0 ]; then
    echo "❌ 數據同步失敗，請檢查 CTB.json 格式。"
    exit 1
fi

# 2. 編譯單次查詢工具 (ctb)
echo -e "${YELLOW}[2/3] 編譯核心引擎... (ctb)${NC}"
g++ CodeToolBox.cpp -o ctb
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ ctb 編譯成功！${NC}"
else
    echo "❌ ctb 編譯失敗。"
    exit 1
fi

# 3. 編譯互動式介面 (ctb_ui)
echo -e "${YELLOW}[3/3] 編譯互動式 UI... (ctb_ui)${NC}"
g++ CTB_UI.cpp -o ctb_ui
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✅ ctb_ui 編譯成功！${NC}"
else
    echo "❌ ctb_ui 編譯失敗。"
    exit 1
fi

echo -e "${BLUE}======================================${NC}"
echo -e "${GREEN}恭喜！所有模組已就緒。${NC}"
echo -e "使用 ${YELLOW}./ctb_ui${NC} 進入互動模式，或使用 ${YELLOW}./ctb <key>${NC} 快速查詢。"
