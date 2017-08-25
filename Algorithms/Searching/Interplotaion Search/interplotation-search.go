/*
 * Interpolation Search
 *
 */

package main

import "fmt"

func InterpolationSearch(arr []int, n, x int) int {
	low := 0
	high := (n - 1)

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	for low <= high && x >= arr[low] && x <= arr[high] {
		// Probing the position with keeping
		// uniform distribution in mind.
		pos := low + (((high - low) / (arr[high] - arr[low])) * (x - arr[low]))

		// Condition of target found
		if arr[pos] == x {
			return pos
		} else if arr[pos] < x {
			// If x is larger, x is in upper part
			low = pos + 1
		} else {
			// If x is smaller, x is in lower part
			high = pos - 1
		}

	}
	return -1
}

func main() {
	arr := []int{3, 5, 12, 56, 92, 123, 156, 190, 201, 222}
	fmt.Println(InterpolationSearch(arr, len(arr), 12))
}
