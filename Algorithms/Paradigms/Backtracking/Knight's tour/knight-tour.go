package main

import (
	"fmt"
)

const (
	N int = 8
)

func isSafe(x, y int, sol [N][N]int) bool {
	return (x >= 0 && x < N && y >= 0 &&
		y < N && sol[x][y] == -1)
}

func SolveKnightTour() bool {
	var sol [N][N]int
	for x := 0; x < N; x++ {
		for y := 0; y < N; y++ {
			sol[x][y] = -1
		}
	}
	xMove := [N]int{2, 1, -1, -2, -2, -1, 1, 2}
	yMove := [N]int{1, 2, 2, 1, -1, -2, -2, -1}

	sol[0][0] = 0

	if SolveKnightTourUtil(0, 0, 1, sol, xMove, yMove) == false {
		fmt.Println("Solution does not exist")
		return false
	} else {
		fmt.Println(sol)
	}
	return true
}

func SolveKnightTourUtil(x, y, movei int, sol [N][N]int, xMove [N]int, yMove [N]int) bool {
	var next_x, next_y int
	if movei == N*N {
		return true
	}

	for k := 0; k < 8; k++ {
		next_x = x + xMove[k]
		next_y = y + yMove[k]
		if isSafe(next_x, next_y, sol) {
			sol[next_x][next_y] = movei
			if SolveKnightTourUtil(next_x, next_y, movei+1, sol, xMove, yMove) == true {
				return true
			} else {
				sol[next_x][next_y] = -1
			}
		}
	}

	return false
}

func main() {
	SolveKnightTour()
}
