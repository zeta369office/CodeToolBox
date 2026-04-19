# 🛠️ CodeToolBox (CTB) - Multi-Lang Snippet Engine
> **Status:** Development 🟢 | **Version:** 0.1.0-alpha | **CNBS Project**

---

## 🌍 Language Hub / 言語ハブ / 語言中心 / 언어 허브

| Language | Module | Goal / 目的 |
| :--- | :--- | :--- |
| **English** | Global | Standardize code retrieval for everyone. |
| **日本語** | 効率化 | コードスニペットを瞬時に取得する。 |
| **繁體中文** | 模組化 | 讓開發者透過模組化工具快速調用代碼。 |
| **한국어** | 생산성 | 코드 스니펫을 신속하게 검색하여 생산성 향상. |

---

## 📖 Introduction / 介紹

### [EN] Quick Summary
CodeToolBox is a cross-platform CLI tool. It bridges the gap between different languages by providing a unified interface to query "How to" code logic.

### [CN] 專案簡介
CodeToolBox 是一個跨平台的命令行工具。它的核心目標是消除語言障礙，讓你在 C++、Python、Rust 之間快速切換，並直接獲取「如何實作某功能」的標準代碼。

---

## 🚀 Getting Started / 快速上手 / 始め方

### 1️⃣ Compile Core (C++)
```bash
# Standard compilation / 標準編譯
# Query pattern: ./ctb <keyword>
./ctb "how_save"
g++ CodeToolBox.cpp -o ctb
🛠️ Developer Ecosystem / 開發者生態 / 開発者エコシステム
DevMode.py (The Editor / 編輯器)
EN: Run this to inject new snippets into CTB.json without touching the C++ logic.

CN: 執行此腳本即可向 CTB.json 注入新代碼，無需修改 C++ 邏輯。

JP: C++ロジックを修正せずに CTB.json に新しいスニペットを追加します。

KR: C++ 로직을 수정하지 않고 CTB.json에 새로운 스니펫을 추가합니다.

Bash
python3 DevMode.py --add
📂 Project Architecture / 專案架構
CodeToolBox.cpp: [Core] Input handling & logic dispatch.

CTB.json: [Data] The brain containing all snippet mappings.

DevMode.py: [Tool] Automated file modifier for contributors.

ctb_hub.rs: [System] High-level integration & Rust safety layer.

ctbHowUse.md: [Doc] Multi-lingual user guide.

📜 License & Open Source
This project is part of the CNBS Plan. Suitable for modification and open-source contribution.
本項目為 CNBS 計畫 的一部分，適合開源與自由修改。
