/*
 * Shell Sort
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

func shellSort() {
	arr := randomArray(10)
	fmt.Println("Shell Sort")
	fmt.Println("Initial array is:", arr)

	for k := int(len(arr) / 2); k > 0; k /= 2 {
		for i := k; i < len(arr); i++ {
			for j := i; j >= k && arr[j-k] > arr[j]; j -= k {
				arr[j], arr[j-k] = arr[j-k], arr[j]
			}
		}
	}

	fmt.Println("Sorted array is: ", arr)
	fmt.Println()
}

func main() {
	shellSort()
}
