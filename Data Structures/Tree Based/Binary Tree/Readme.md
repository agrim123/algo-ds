# Binary Tree

Binary Tree is a special data structure used for data storage purposes.  
A tree whose `elements have at most 2 children` is called a binary tree. Since each element in a binary tree can have only 2 children, we name them the `left` and `right` child.  

> A binary tree has the benefits of both an ordered array and a linked list as search is as quick as in a sorted array and insertion or deletion operation are as fast as in linked list.  

## Properties

1. The maximum number of nodes at level `l` of a binary tree is `2^(l-1)`.
2. Maximum number of nodes in a binary tree of height `h` is `2h – 1`.
3. In a Binary Tree with N nodes, minimum possible height or minimum number of levels is  `Log2(N+1)`
4. A Binary Tree with L leaves has at least `(Log2l) + 1`   levels.
5. In Binary tree, number of leaf nodes is always one more than nodes with two children.

## Types of Binary Trees

1. **Full Binary Tree** : A Binary Tree is full if every node has 0 or 2 children.
2. **Complete Binary Tree**: A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible
3. **Perfect Binary Tree**: A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at same level.
4. **Balanced Binary Tree**

## Handshaking Lemma and Interesting Tree Properties

[Handshaking Lemma](https://en.wikipedia.org/wiki/Handshaking_lemma) is about undirected graph. In every finite undirected graph number of vertices with odd degree is always even. Properties:
1. In a k-ary tree where every node has either 0 or k children, following property is always true:
```bash
    L = (k - 1)*I + 1
Where L = Number of leaf nodes
      I = Number of internal nodes 
```
2. In Binary tree, number of leaf nodes is always one more than nodes with two children.
```bash
    L = T + 1
Where L = Number of leaf nodes
      T = Number of internal nodes with two children
```

## References

- [Geeks For Geeks](geeksforgeeks.org)
