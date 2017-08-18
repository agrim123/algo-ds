/*
 *  Insertion Sort
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

func insertionSort() {
	arr := randomArray(10)
	fmt.Println("Insertion Sort")
	fmt.Println("Initial array is: ", arr)

	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}

	fmt.Println("Sorted array is: ", arr)
	fmt.Println()
}

func main() {
	insertionSort()
}
