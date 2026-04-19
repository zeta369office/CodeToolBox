use std::process::Command;
use std::io::{self, Write};

/**
 * MODULE: System Integrator
 * 這是你的 CNBS 計畫在 Win11 上的 Rust 實作
 */
fn main() {
    println!("--- CodeToolBox Rust Hub (Win11) ---");
    
    loop {
        print!("hub> ");
        io::stdout().flush().unwrap();

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        let query = input.trim();

        // 1. 退出邏輯
        if query == "goto exit" {
            println!("Rust Hub shutting down...");
            break;
        }

        // 2. 呼叫你編譯好的 C++ 核心 (ctb.exe)
        // 假設你的 ctb.exe 就在同一個資料夾
        let output = Command::new("./ctb.exe")
            .arg(query)
            .output();

        match output {
            Ok(out) => {
                let result = String::from_utf8_lossy(&out.stdout);
                if result.is_empty() {
                    println!("[!] C++ Core returned nothing.");
                } else {
                    println!("{}", result);
                }
            }
            Err(_) => println!("[!] Error: Could not find ctb.exe. Did you build it?"),
        }
    }
}