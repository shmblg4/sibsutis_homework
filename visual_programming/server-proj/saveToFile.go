package main

import (
	"log"
	"os"
)

func saveToFile(data string) {
	file, err := os.OpenFile("data.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		log.Fatalf("Ошибка при открытии файла для записи: %v", err)
	}
	defer file.Close()

	if _, err := file.WriteString(data + "\n"); err != nil {
		log.Printf("Ошибка при записи данных в файл: %v", err)
	}
}
