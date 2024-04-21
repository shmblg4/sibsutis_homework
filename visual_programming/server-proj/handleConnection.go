package main

import (
	"fmt"
	"log"
	"net"
)

func handleConnection(conn net.Conn) {
	defer conn.Close()

	buffer := make([]byte, 1024)
	n, err := conn.Read(buffer)
	if err != nil {
		log.Printf("Ошибка при чтении данных от клиента: %v", err)
		return
	}

	data := string(buffer[:n])
	fmt.Printf("Получены данные от клиента: %s\n", data)

	saveToFile(data)

	_, err = conn.Write([]byte("Данные получены и сохранены\n"))
	if err != nil {
		log.Printf("Ошибка при отправке данных клиенту: %v", err)
	}
}
