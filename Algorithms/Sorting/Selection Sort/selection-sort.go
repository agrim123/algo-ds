/*
 * Selection Sort
 *
 */

package main

import (
	"fmt"
	"math/rand"
)

func randomArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = rand.Intn(n)
	}
	return arr
}

func SelectionSort() {
	arr := randomArray(10)
	fmt.Println("Selection Sort")
	fmt.Println("Initial array is: ", arr)

	var min int = 0
	var temp int = 0

	for i := 0; i < len(arr); i++ {
		min = i
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[min] {
				min = j
			}
		}
		temp = arr[i]
		arr[i] = arr[min]
		arr[min] = temp
	}

	fmt.Println("Sorted array: ", arr)
	fmt.Println()
}

func main() {
	SelectionSort()
}
