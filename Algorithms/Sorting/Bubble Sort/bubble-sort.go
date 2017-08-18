/*
 * Bubble Sort
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

func bubbleSort() {
	arr := randomArray(10)
	fmt.Println("Bubble Sort")
	fmt.Println("Initial array is: ", arr)

	temp := 0

	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-1; j++ {
			if arr[j] > arr[j+1] {
				temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
			}
		}
	}

	fmt.Println("Sorted array is: ", arr)
	fmt.Println()
}

func main() {
	bubbleSort()
}
