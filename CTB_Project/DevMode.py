import json
import os
import sys

# --- Configuration ---
JSON_FILE = 'CTB.json'
HEADER_FILE = 'data.h'

def generate_header():
    """核心功能：將 JSON 轉換為 C++ 萬用標頭檔 (修正括號版)"""
    try:
        if not os.path.exists(JSON_FILE):
            print(f"Error: {JSON_FILE} 不存在！")
            return

        with open(JSON_FILE, 'r', encoding='utf-8') as f:
            data = json.load(f)

        header_content = """#ifndef DATA_H
#define DATA_H
#include <string>
#include <map>

struct Snippet {
    std::map<std::string, std::string> langs;
};

// 自動生成的全語言數據庫
inline std::map<std::string, Snippet> code_db = {
"""
        for key, value in data.get('snippets', {}).items():
            # C++ 初始化語法： { "key", { { {"lang", "code"} } } }
            header_content += f'    {{"{key}", {{ {{ \n'
            for lang, code in value.items():
                if lang == "desc": continue
                # 轉義引號與換行符
                clean_code = code.replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n')
                header_content += f'        {{"{lang}", "{clean_code}"}},\n'
            header_content += f'    }} }} }},\n'

        header_content += "};\n#endif"

        with open(HEADER_FILE, 'w', encoding='utf-8') as f:
            f.write(header_content)
        print(f"✅ {HEADER_FILE} 已修正並更新！")
    except Exception as e:
        print(f"❌ 生成失敗: {e}")

def import_from_file(filename):
    """批量功能：從外部 list.txt 快速導入數據"""
    if not os.path.exists(filename):
        print(f"❌ 找不到導入檔案: {filename}")
        return

    try:
        if os.path.exists(JSON_FILE):
            with open(JSON_FILE, 'r', encoding='utf-8') as f:
                data = json.load(f)
        else:
            data = {"version": "0.1.0", "snippets": {}}

        with open(filename, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                if not line or '|' not in line: continue
                
                parts = [p.strip() for p in line.split('|', 2)]
                if len(parts) == 3:
                    key, lang, code = parts
                    if 'snippets' not in data: data['snippets'] = {}
                    if key not in data['snippets']:
                        data['snippets'][key] = {"desc": f"Batch import"}
                    data['snippets'][key][lang] = code
                    print(f"📥 載入成功: [{key}] -> {lang}")

        with open(JSON_FILE, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=4, ensure_ascii=False)
        
        generate_header()
    except Exception as e:
        print(f"❌ 導入過程中出錯: {e}")

if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--import":
        import_from_file(sys.argv[2])
    else:
        generate_header()
