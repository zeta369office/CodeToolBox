/**
 * @file CodeToolBox.cpp
 * @brief Universal Snippet Engine / 全語言通用檢索引擎
 */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "data.h" // 引用自動生成的數據

/**
 * MODULE: Logic
 * 遍歷所有存儲在 map 中的語言並輸出
 */
void handleQuery(std::string query) {
    if (code_db.find(query) != code_db.end()) {
        Snippet s = code_db[query];
        
        std::cout << "\n[ Result for: " << query << " ]\n" << std::endl;
        
        // 自動遍歷所有語言，不需要手動指定 cpp 或 python
        for (auto const& [lang, code] : s.langs) {
            std::cout << "--- " << lang << " ---" << std::endl;
            std::cout << code << "\n" << std::endl;
        }
    } else {
        std::cout << "[!] Unknown Command: " << query << " / 找不到該指令" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./ctb <keyword>\n";
        return 1;
    }
    handleQuery(argv[1]);
    return 0;
}
