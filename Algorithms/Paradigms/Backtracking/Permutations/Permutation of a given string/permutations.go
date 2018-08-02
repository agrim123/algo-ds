package main

import (
	"fmt"
)

func Permute(str []rune, i int) {
	if i == len(str) {
		fmt.Println(string(str))
	} else {
		for j := i; j < len(str); j++ {
			str[i], str[j] = str[j], str[i]
			Permute(str, i+1)
			str[i], str[j] = str[j], str[i]
		}
	}
}

func main() {
	str := "ABCDER"
	Permute([]rune(str), 0)
}
