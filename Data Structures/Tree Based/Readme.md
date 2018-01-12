# Trees

Tree represents the nodes connected by edges  
Unlike Arrays, Linked Lists, Stack and queues, which are linear data structures, trees are `hierarchical data structures`.  
The topmost node of tree is called `root of the tree`. Elements directly under it are its `children` and element directly above it is its `parent`. Elements with no children are called `leaves`.

```
       r           -> root
      / \
    c1   c2        -> children (of their respective parents)
   / \    \
  l1 l2    l3      -> leaves
```

## Basic Operations

- **Insert** − Insert an element in a tree/create a tree.

- **Search** − Searche an element in a tree.

- **Preorder Traversal** − Traverses a tree in a pre-order manner.

- **Inorder Traversal** − Traverses a tree in an in-order manner. (also in sorted manner in case of BST)

- **Postorder Traversal** − Traverses a tree in a post-order manner.

Consider a tree  
```
     A
   /   \
  B     C
 / \   / \
D   E F   G
```

**Preorder Traversal** : The root node is visited first, then the left subtree and finally the right subtree. 
The output of pre-order traversal of this tree will be −

`A → B → D → E → C → F → G`  

**Inorder Traversal** : The left subtree is visited first, then the root and later the right sub-tree. We should always remember that every node may represent a subtree itself.  
The output of pre-order traversal of this tree will be −

`D → B → E → A → F → C → G`  

**Postorder Traversal** : The root node is visited last, hence the name. First we traverse the left subtree, then the right subtree and finally the root node.  
The output of pre-order traversal of this tree will be −

`D → E → B → F → G → C → A`

## Representation

A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of root is NULL.  
A Tree node contains following parts.
1. Data
2. Pointer to left child
3. Pointer to right child


## Reasons for using trees

1. We want to store information that naturally forms a hierarchy. Example file system on computer.
2. Trees (with some ordering e.g., BST) provide moderate access/search (quicker than Linked List and slower than arrays).
3. Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists).
4. Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers.

## Applications

1. Manipulate hierarchical data.
2. Make information easy to search (see tree traversal).
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms
6. Form of a multi-stage decision-making (see business chess).

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Tree](https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm)
- [Data Structure and Algorithms - Tree Traversal](https://www.tutorialspoint.com/data_structures_algorithms/tree_traversal.htm)
- https://en.wikipedia.org/wiki/Tree_%28data_structure%29
