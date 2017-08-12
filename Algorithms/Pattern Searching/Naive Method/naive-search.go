/*
 * Naive Pattern Searching
 *
 */

package main

import (
	"fmt"
)

func searchPattern(txt, pattern string) {
	n := len(txt)
	m := len(pattern)
	for i := 0; i <= n-m; i++ {
		var j int
		for j = 0; j < m; j++ {
			if txt[i+j] != pattern[j] {
				break
			}
		}
		if j == m {
			fmt.Println("pattern found at index n = ", i)
		}
	}
}

func main() {
	txt := "AABAACAADAABAAABAA"
	pattern := "CAADAA"
	searchPattern(txt, pattern)
}
