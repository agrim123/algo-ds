/*
 * Quick sort
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

func quickSort(arr []int) []int {

	if len(arr) <= 1 {
		return arr
	}

	median := arr[rand.Intn(len(arr))]

	l := make([]int, 0, len(arr))
	h := make([]int, 0, len(arr))
	m := make([]int, 0, len(arr))

	for _, item := range arr {
		switch {
		case item < median:
			l = append(l, item)
		case item == median:
			m = append(m, item)
		case item > median:
			h = append(h, item)
		}
	}

	l = quickSort(l)
	h = quickSort(h)

	l = append(l, m...)
	l = append(l, h...)

	return l
}

func main() {
	arr := randomArray(10)
	fmt.Println("Initial array is:", arr)
	fmt.Println()
	fmt.Println("Sorted array is: ", quickSort(arr))
}
