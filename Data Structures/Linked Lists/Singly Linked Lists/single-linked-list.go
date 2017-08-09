// Double Linked Lists

package main

import (
	"fmt"
)

type Node struct {
	key  interface{}
	next *Node
}

type SingleLinkedList struct {
	head *Node
}

func (l *SingleLinkedList) Insert(key interface{}) {
	new_node := &Node{key, l.head}
	l.head = new_node
}

func (l *SingleLinkedList) Append(key interface{}) {
	new_node := &Node{key, nil}
	if l.head == nil {
		l.head = new_node
		return
	}

	last := l.head
	for last.next != nil {
		last = last.next
	}
	last.next = new_node
	return
}

func (l *SingleLinkedList) Delete(key interface{}) {
	temp := l.head
	prev := &Node{}
	if temp != nil && temp.key == key {
		l.head = temp.next
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

func (l *SingleLinkedList) Show() {
	SingleLinkedList := l.head
	for SingleLinkedList != nil {
		fmt.Printf("%+v -> ", SingleLinkedList.key)
		SingleLinkedList = SingleLinkedList.next
	}
	fmt.Println()
}

func main() {
	l := SingleLinkedList{}
	l.Insert(1)
	l.Insert(2)
	l.Insert(3)
	l.Insert(4)
	l.Insert(5)
	l.Insert(6)
	l.Append(9)
	l.Delete(5)
	l.Show()
}
