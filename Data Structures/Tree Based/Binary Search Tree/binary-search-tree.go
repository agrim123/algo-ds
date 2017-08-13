/*
   Binary Search Trees
       - Basic Operations
           - Search
           - Insert
*/

package main

import (
	"fmt"
)

type Node struct {
	key         int
	left, right *Node
}

type BinarySearchTree struct {
	root *Node
}

func (n *Node) InsertNewNode(key int) {
	newNode := &Node{key, nil, nil}
	if newNode.key > n.key {
		if n.right == nil {
			n.right = newNode
		} else {
			n.right.InsertNewNode(key)
		}
	} else if newNode.key < n.key {
		if n.left == nil {
			n.left = newNode
		} else {
			n.left.InsertNewNode(key)
		}
	}
}

func (n *Node) Find(key int) bool {
	if n != nil {
		if key == n.key {
			return true
		} else if key > n.key {
			return n.right.Find(key)
		} else {
			return n.left.Find(key)
		}
	}
	return false
}

func (t *BinarySearchTree) Insert(key int) {
	if t.root == nil {
		t.root = &Node{key, nil, nil}
	}
	t.root.InsertNewNode(key)
}

func (t *BinarySearchTree) Search(key int) bool {
	return t.root.Find(key)
}

func main() {
	tree := &BinarySearchTree{}
	tree.Insert(2)
	tree.Insert(1)
	tree.Insert(4)
	tree.Insert(5)
	fmt.Println(tree.root)
	fmt.Println(tree.Search(1))
}
