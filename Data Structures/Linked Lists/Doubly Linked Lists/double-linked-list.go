// Double Linked Lists

package main

import (
	"fmt"
)

type Node struct {
	key  interface{}
	next *Node
	prev *Node
}

type List struct {
	head *Node
	tail *Node
}

func (l *List) Insert(key interface{}) {
	new_node := &Node{key, l.head, nil}
	if l.head != nil {
		l.head.prev = new_node
	}
	l.head = new_node
}

func (l *List) Delete(key interface{}) {
	temp := l.head
	prev := &Node{}
	if temp != nil && temp.key == key {
		l.head = temp.next
		temp.next.prev = l.head
		return
	}
	for temp != nil && temp.key != key {
		prev = temp
		temp = temp.next
	}
	if temp == nil {
		return
	}
	prev.next = temp.next
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
	l.Delete(1)
	l.Delete(9)
	l.Show()
}
