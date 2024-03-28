package main

import (
	"fmt"
	"os"
)

func main() {
	mas := []int{}
	size := 0
	k := 0

	fmt.Println("Введите размер")
	var n int
	var err error
	n, err = fmt.Fscan(os.Stdin, &size)
	if n == -1 || err != nil {
		os.Exit(-1)
	}

	for i := 0; i < size; i++ {
		n, err = fmt.Scan(&k)
		if n == -1 || err != nil {
			break
		}
		mas = append(mas, k)
	}

	fmt.Println("Введите k")
	n, err = fmt.Fscan(os.Stdin, &k)
	if n == -1 || err != nil {
		os.Exit(-1)
	}

	maxelem := -100000
	var check int = 0
	for i := 0; i < size; i++ {
		if maxelem < mas[i] {
			maxelem = mas[i]
			check++
			if check >= k {
				break
			}
		}
	}

	fmt.Println(mas, maxelem, k)

}
