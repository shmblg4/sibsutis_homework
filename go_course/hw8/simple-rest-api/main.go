package main

import (
	"encoding/json"
	"log"
	"net/http"
)

type Item struct {
	ID   string `json:"id"`
	Name string `json:"name"`
}

var items []Item

func main() {
	// Установка обработчиков маршрутов
	http.HandleFunc("/", indexHandler)
	http.HandleFunc("/items", getItems)
	http.HandleFunc("/items/add", addItem)

	// Запуск сервера на порту 8080
	log.Fatal(http.ListenAndServe(":8080", nil))
}

// Обработчик для главной страницы
func indexHandler(w http.ResponseWriter, r *http.Request) {
	http.ServeFile(w, r, "index.html")
}

// Обработчик для получения списка всех элементов
func getItems(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	json.NewEncoder(w).Encode(items)
}

// Обработчик для добавления нового элемента
func addItem(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	var newItem Item
	err := json.NewDecoder(r.Body).Decode(&newItem)
	if err != nil {
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	items = append(items, newItem)
	json.NewEncoder(w).Encode(items)
}
