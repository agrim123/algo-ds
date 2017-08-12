/*
 * Jump Search
 *
 */

package main

import (
	"fmt"
	"math"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func JumpSearch(arr []int, n, x int) int {
	step := int(math.Floor(math.Sqrt(float64(n))))
	prev := 0
	for arr[min(step, n)-1] < x {
		prev = step
		step += int(math.Floor(math.Sqrt(float64(n))))
		if prev >= n {
			return -1
		}
	}
	for arr[prev] < x {
		prev++
		if prev == min(step, n) {
			return -1
		}
	}
	if arr[prev] == x {
		return prev
	}
	return -1

}

func main() {
	arr := []int{3, 5, 12, 56, 92, 123, 156, 190, 201, 222}
	fmt.Print("Jump Search :: ")
	fmt.Println(JumpSearch(arr, len(arr), 12))
}
