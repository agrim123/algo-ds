/*
 *  Sorting
 *    - Insertion Sort
 *    - Bubble Sort
 *    - Selection Sort
 *    - Shell Sort
 *    - Count Sort
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

func selectionSort() {
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

func countSort() {
	arr := randomArray(10)
	fmt.Println("Count Sort")
	fmt.Println("Initial array is:", arr)

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

	fmt.Println("Sorted array is: ", arr)
	fmt.Println()
}
func main() {
	bubbleSort()
	insertionSort()
	selectionSort()
	shellSort()
	countSort()
}
