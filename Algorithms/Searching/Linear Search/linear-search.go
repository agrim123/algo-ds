/*
 * Linear Search
 *
 */

package main

import "fmt"

func LinearSearch(arr []int, k int) int {
	for i := 0; i < len(arr); i++ {
		if arr[i] == k {
			return i
		}
	}
	return -1
}

func main() {
	arr := []int{3, 5, 12, 56, 92, 123, 156, 190, 201, 222}
	fmt.Println(LinearSearch(arr, 12))
}
