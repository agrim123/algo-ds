/*
 * 0-1 Knapsack Problem
 *
 */

package main

import (
	"fmt"
)

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func KnapSackDP(W int, wt, val []int, n int) int {
	K := make([][]int, n+1)
	for i := range K {
		K[i] = make([]int, W+1)
	}

	for i := 0; i <= n; i++ {
		for j := 0; j <= W; j++ {
			if i == 0 || j == 0 {
				K[i][j] = 0
			} else if wt[i-1] <= j {
				K[i][j] = max(val[i-1]+K[i-1][j-wt[i-1]], K[i-1][j])
			} else {
				K[i][j] = K[i-1][j]
			}
		}
	}
	return K[n][W]
}

func main() {
	val := []int{60, 100, 120}
	wt := []int{10, 20, 30}
	W := 60
	fmt.Println(KnapSackDP(W, wt, val, len(val)))
}
