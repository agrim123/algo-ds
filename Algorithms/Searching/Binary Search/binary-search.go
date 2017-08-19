/*
 * Binary Search
 *
 */

package main

import (
	"fmt"
)

func BinarySearch(arr []int, l, r, x int) int {
	if r >= l {
		mid := l + (r-l)/2
		if arr[mid] == x {
			return mid
		} else if arr[mid] > x {
			return BinarySearch(arr, l, mid-1, x)
		} else {
			return BinarySearch(arr, mid+1, r, x)
		}
	}
	return -1
}

func main() {
	arr := []int{3, 5, 12, 56, 92, 123, 156, 190, 201, 222}
	n := len(arr)
	x := 12
	l := 0
	r := n - 1
	fmt.Println(BinarySearch(arr, l, r, x))
}
