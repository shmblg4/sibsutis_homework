package main

import (
	"calculations/calculations"
	"flag"
	"fmt"
	"os"
	"strconv"
)

func main() {
	variables := []int64{}
	log := flag.Bool("log", false, "Do loging or not")
	flag.Parse()
	var args[]string
	if *log {
		args = os.Args[2:]
	} else {
		args = os.Args[1:]
	}
	fmt.Println(args)
	for _, arg := range args {
		num, err := strconv.ParseInt(arg, 10, 64)
		if err != nil {
			fmt.Println("Incorrect input")
			os.Exit(1)
		}
		variables = append(variables, num)
	}

	for _, num := range variables {
		res := calculations.Calculate(num, *log)
		fmt.Println(res)
	}
}
