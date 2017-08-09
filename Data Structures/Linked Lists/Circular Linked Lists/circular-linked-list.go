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

type CircularLinkedList struct {
	head *Node
}

func (l *CircularLinkedList) Insert(key interface{}) {
	ptr := &Node{
		next: l.head,
		key:  key,
	}
	temp := l.head
	if l.head != nil {
		for temp.next != l.head {
			temp = temp.next
		}
		temp.next = ptr
	} else {
		ptr.next = ptr
	}

	l.head = ptr
}

func (l *CircularLinkedList) Show() {
	CircularLinkedList := l.head
	for CircularLinkedList != nil {
		fmt.Printf("%+v -> ", CircularLinkedList.key)
		CircularLinkedList = CircularLinkedList.next
		if CircularLinkedList == l.head {
			break
		}
	}
	fmt.Println()
}

func main() {
	l := CircularLinkedList{}
	l.Insert(1)
	l.Insert(2)
	l.Insert(3)
	l.Insert(4)
	l.Insert(5)
	l.Insert(6)
	l.Show()
}
