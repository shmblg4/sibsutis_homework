package main

import (
	"fmt"
	"log"
	"net"
)

func main() {
	address := "127.0.0.1:12345"

	ln, err := net.Listen("tcp", address)
	if err != nil {
		log.Fatalf("Ошибка при запуске сервера: %v", err)
	}
	defer ln.Close()

	fmt.Printf("Сервер запущен и слушает по адресу %s\n", address)

	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Printf("Ошибка при принятии подключения: %v", err)
			continue
		}

		go handleConnection(conn)
	}
}
