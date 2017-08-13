/*
 * Maze size
 *
 */

package main

import (
	"fmt"
)

const (
	N int = 4
)

func isSafe(maze [N][N]int, x, y int) bool {
	// if (x,y outside maze) return false
	return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
}

/* This function solves the Maze problem using Backtracking.  It mainly
   uses SolveMazeUtil() to solve the problem. It returns false if no
   path is possible, otherwise return true and prints the path in the
   form of 1s. Please note that there may be more than one solutions,
   this function prints one of the feasible solutions.*/
func SolveMaze(maze [N][N]int) bool {
	sol := [N][N]int{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	}

	if SolveMazeUtil(maze, 0, 0, sol) == false {
		fmt.Println("Solution doesn't exist")
		return false
	}

	fmt.Println(sol)
	return true
}

func SolveMazeUtil(maze [N][N]int, x, y int, sol [N][N]int) bool {
	// if (x,y is goal) return true
	if x == N-1 && y == N-1 {
		sol[x][y] = 1
		return true
	}

	// Check if maze[x][y] is valid
	if isSafe(maze, x, y) == true {
		// mark x,y as part of solution path
		sol[x][y] = 1

		// Move forward in x direction
		if SolveMazeUtil(maze, x+1, y, sol) == true {
			return true
		}

		// If moving in x direction doesn't give solution then Move down in y direction
		if SolveMazeUtil(maze, x, y+1, sol) == true {
			return true
		}

		// If none of the above movements work then BACKTRACK: unmark x,y as part of solution path
		sol[x][y] = 0
		return false
	}

	return false
}

func main() {
	maze := [N][N]int{
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{1, 1, 1, 0},
		{1, 1, 1, 1},
	}
	SolveMaze(maze)
}
