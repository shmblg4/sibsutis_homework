//go:generate go run random.go

package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println("Random number:", rand.Intn(100))
}

func init() {
	fmt.Println("Generating random number...")
	fmt.Println("Random number:", rand.Intn(100))
	os.Exit(0)
}
