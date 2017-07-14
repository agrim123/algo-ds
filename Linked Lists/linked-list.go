package main

import (
	"fmt"
)

type Node struct {
	x    int
	next *Node
	prev *Node
}

func main() {
	b := Node{3, nil, nil}
	c := Node{4, nil.nil}
	c.prev = b
	b.next = c
	fmt.Println(b)
}
