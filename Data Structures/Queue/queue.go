/*
   Queue
        - Linked Lists Implementation
        - First In First Out (FIFO)
        - Three basic operations on Queues:
             1. Enqueue -> add item to rear
             2. Dequeue -> remove item from front
*/

package main

import "fmt"

type Queue struct {
	first *Node
	size  int
}

type Node struct {
	val  interface{}
	next *Node
}

func (q *Queue) Length() int {
	return q.size
}

func (q *Queue) isEmpty() bool {
	return q.size == 0
}

func (q *Queue) Enqueue(val interface{}) {
	n := &Node{val, nil}
	if q.first == nil {
		q.first = n
	} else {
		last := q.first
		for last.next != nil {
			last = last.next
		}
		last.next = n
	}
	q.size++
}

func (q *Queue) Dequeue() (val interface{}) {
	if q.size > 0 {
		val, q.first = q.first.val, q.first.next
		q.size--
		return
	}
	return ""
}

func main() {
	queue := new(Queue)

	queue.Enqueue("Google")
	queue.Enqueue("Facebook")
	queue.Dequeue()
	queue.Enqueue("StackOverflow")
	queue.Enqueue("Youtube")

	for queue.Length() > 0 {
		fmt.Printf("%s ", queue.Dequeue().(string))
	}
	fmt.Println()
}
