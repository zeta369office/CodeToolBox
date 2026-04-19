/**
 * @file CTB_UI.cpp
 * @brief Interactive Shell for CodeToolBox
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "data.h" // 複用你強大的數據庫

// 複用之前的 handleQuery 邏輯
void handleQuery(std::string query) {
    if (code_db.find(query) != code_db.end()) {
        Snippet s = code_db[query];
        std::cout << "\n[ " << query << " ]" << std::endl;
        for (auto const& [lang, code] : s.langs) {
            std::cout << ">>> " << lang << ":\n" << code << "\n" << std::endl;
        }
    } else {
        std::cout << "[!] 未找到關鍵字: " << query << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "--- CodeToolBox Interactive Mode ---" << std::endl;
    std::cout << "Type 'goto exit' to quit. / 輸入 'goto exit' 退出。" << std::endl;

    while (true) {
        std::cout << "ctb> ";
        std::getline(std::cin, input); // 使用 getline 以支持空格

        // 1. 處理退出邏輯
        if (input == "goto exit") {
            std::string confirm;
            std::cout << "Confirm exit? [y/n]: ";
            std::cin >> confirm;
            if (confirm == "y" || confirm == "Y") {
                std::cout << "Goodbye! / 掰掰！" << std::endl;
                break;
            }
            std::cin.ignore(); // 清除緩衝區，防止干擾下次 getline
            continue;
        }

        // 2. 處理單純的關鍵字輸入
        if (input.empty() || input == "goto" || input == "exit") {
            // 如果只是單獨輸入 goto 或 exit，不執行動作，繼續等待
            continue;
        }

        // 3. 執行查詢
        handleQuery(input);
    }

    return 0;
}
