/*
 * Merge sort
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

func Merge(l, r []int) []int {
	result := make([]int, 0, len(l)+len(r))

	for len(l) > 0 || len(r) > 0 {
		if len(l) == 0 {
			return append(result, r...)
		}
		if len(r) == 0 {
			return append(result, l...)
		}
		if l[0] <= r[0] {
			result = append(result, l[0])
			l = l[1:]
		} else {
			result = append(result, r[0])
			r = r[1:]
		}
	}

	return result
}

func MergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	middle := len(arr) / 2

	l := MergeSort(arr[:middle])
	r := MergeSort(arr[middle:])

	return Merge(l, r)
}

func main() {
	arr := randomArray(10)
	fmt.Println("Initial array is:", arr)
	fmt.Println("")
	fmt.Println("Sorted array:    ", MergeSort(arr))
}
