// Binary Tree

package main

import "fmt"

type Node struct {
	left, right, parent *Node
	value               int
}

type BinaryTree struct {
	root *Node
}

func addNode(parent *Node, val int) *Node {
	return &Node{nil, nil, parent, val}
}

func (b *BinaryTree) Insert(val int) (n *Node) {
	if b.root == nil {
		n = addNode(nil, val)
		b.root = n
	} else {
		n = b.insert(b.root, nil, val)
	}
	return
}

func (b *BinaryTree) insert(root *Node, parent *Node, val int) *Node {
	switch {
	case root == nil:
		return addNode(parent, val)
	case val <= root.value:
		root.left = b.insert(root.left, root, val)
	case val > root.value:
		root.right = b.insert(root.right, root, val)
	}
	return root
}

func main() {
	b := new(BinaryTree)
	b.Insert(0)
	b.Insert(1)
	b.Insert(2)
	fmt.Println(b.root)
}
