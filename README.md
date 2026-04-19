# CodeToolBox (CTB) 🚀

[English](#english) | [中文說明](#中文說明)

---

## English

CodeToolBox is an automated, multi-language code snippet management system designed for developers who work across various programming environments.** social software project.

### ✨ Key Features
- **Multi-Engine Support**: Built with a C++ query core and a Go-based interactive manager.
- **Automated Data Sync**: Python scripts bridge JSON datasets to C++ header files.
- **Modular Architecture**: Clean separation between data, core logic, and UI.

### 🚀 Quick Start
1. **Prerequisites**: Ensure `g++` and `golang` are installed in your environment (WSL recommended).
2. **Build**: Run `./build.sh` to synchronize data and compile all modules.
3. **Run**: 
   - Interactive Mode: `./ctb_manager`
   - Direct Query: `./ctb <keyword>`

---

## 中文說明

CodeToolBox (CTB) 是一個全自動的跨語言代碼片段管理系統，專為需要在多種編程環境間切換的開發者設計。

### ✨ 核心特性
- **多引擎支持**: 結合 C++ 高效查詢核心與 Go 語言交互式管理器。
- **全自動數據同步**: 透過 Python 腳本將 JSON 數據庫自動轉譯為 C++ 標頭檔。
- **模組化架構**: 數據層、核心邏輯層與用戶介面層完全解耦。

### 🚀 快速上手
1. **環境準備**: 確保系統已安裝 `g++` 與 `golang`（推薦使用 WSL 環境）。
2. **自動編譯**: 執行 `./build.sh` 進行數據同步與全模組編譯。
3. **執行程式**: 
   - 互動模式: `./ctb_manager`
   - 快速查詢: `./ctb <關鍵字>`

---

## 📂 Project Structure / 專案結構
- `DevMode.py`: Data converter (JSON to C++).
- `CTB.json`: Centralized code database.
- `src/CodeToolBox.cpp`: High-performance C++ core.
- `src/ctb_manager.go`: Lightweight Go interface.

## 📄 License
This project is licensed under the **MIT License**.
