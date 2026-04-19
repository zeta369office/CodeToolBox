package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
)

func main() {
	// 1. 讀取 JSON
	file, err := ioutil.ReadFile("CTB.json")
	if err != nil {
		fmt.Println("[!] 找不到 CTB.json，請先執行 DevMode.py")
		return
	}

	var data map[string]interface{}
	json.Unmarshal(file, &data)

	// 取得 snippets 層級
	snippets, ok := data["snippets"].(map[string]interface{})
	if !ok {
		fmt.Println("[!] JSON 格式錯誤")
		return
	}

	fmt.Println("--- CodeToolBox Go Manager ---")
	fmt.Println("輸入關鍵字查詢，或輸入 'exit' 退出。")

	for {
		fmt.Print("go_hub> ")
		var input string
		fmt.Scanln(&input)

		if input == "exit" || input == "goto exit" {
			fmt.Println("Goodbye!")
			break
		}

		if input == "" {
			continue
		}

		// 2. 查詢邏輯
		if val, ok := snippets[input]; ok {
			content := val.(map[string]interface{})
			fmt.Printf("\n[ Result for: %s ]\n", input)
			for lang, code := range content {
				if lang == "desc" {
					continue
				}
				fmt.Printf("--- %s ---\n%s\n\n", lang, code)
			}
		} else {
			fmt.Printf("[!] 找不到關鍵字: %s\n", input)
		}
	}
}
