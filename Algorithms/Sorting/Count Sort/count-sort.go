/*
 * Count Sort
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

func getMax(arr []int) int {
	if len(arr) == 0 {
		return 1
	}

	k := arr[0]

	for _, v := range arr {
		if v > k {
			k = v
		}
	}

	return k + 1
}

func countSort(arr []int) []int {
	k := getMax(arr)
	a := make([]int, k)

	for i := 0; i < len(arr); i++ {
		a[arr[i]] += 1
	}

	for i, j := 0, 0; i < k; i++ {
		for {
			if a[i] > 0 {
				arr[j] = i
				j += 1
				a[i] -= 1
				continue
			}
			break
		}
	}
	return arr
}

func main() {
	fmt.Println("Count Sort")
	arr := randomArray(10)
	fmt.Println("Initial array is:", arr)
	fmt.Println("Sorted array is: ", countSort(arr))
	fmt.Println()
}
