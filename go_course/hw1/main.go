package main

import (
	"fmt"
	"os"
)

func calculation(x int, y int, operation string) {
	switch operation {
	case "+":
		fmt.Printf("%d + %d = %d", x, y, x+y)
		break
	case "*":
		fmt.Printf("%d * %d = %d", x, y, x*y)
		break
	case "-":
		fmt.Printf("%d - %d = %d", x, y, x-y)
		break
	case "/":
		fmt.Printf("%d / %d = %d", x, y, x/y)
		break
	default:
		break
	}
}

func CheckOperator(operator string) bool {
	var operations [4]string = [4]string{"+", "-", "*", "/"}
	for index := range operations {
		if operator == operations[index] {
			return false
		}
	}
	return true
}

func main() {
	var x int
	var y int
	var operation string
	var err error
	var n int
	fmt.Println("Введите 1 число")
	n, err = fmt.Scan(&x)
	if n == -1 || err != nil {
		fmt.Println("Неправильное значение переменной")
		os.Exit(-1)
	}
	fmt.Println("Введите операцию (+, -, * или /)")
	fmt.Fscan(os.Stdin, &operation)
	if CheckOperator(operation) {
		fmt.Println("Неверный оператор")
		os.Exit(-1)
	}
	fmt.Println("Введите 2 число")
	n, err = fmt.Scan(&y)
	if n == -1 || err != nil {
		fmt.Println("Неправильное значение переменной")
		os.Exit(-1)
	}
	if y == 0 {
		fmt.Println("Деление на ноль невозможно")
		os.Exit(-1)
	}

	calculation(x, y, operation)
}
