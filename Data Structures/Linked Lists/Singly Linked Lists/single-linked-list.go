// Double Linked Lists

package main

import (
	"fmt"
)

type Node struct {
	key  interface{}
	next *Node
}

type List struct {
	head *Node
	tail *Node
}

func (l *List) Insert(key interface{}) {
	list := &Node{
		next: l.head,
		key:  key,
	}
	l.head = list

	L := l.head
	for L.next != nil {
		L = L.next
	}
	l.tail = L
}

func (l *List) Show() {
	list := l.head
	for list != nil {
		fmt.Printf("%+v -> ", list.key)
		list = list.next
	}
	fmt.Println()
}

func main() {
	l := List{}
	l.Insert(1)
	l.Insert(2)
	l.Insert(3)
	l.Insert(4)
	l.Insert(5)
	l.Insert(6)
	l.Show()
}
