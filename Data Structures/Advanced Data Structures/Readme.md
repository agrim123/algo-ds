# Advanced Data Structures

## [Advanced Lists](Advanced%20Lists)

### [XOR Linked Lists : A Memory Efficient Doubly Linked Lists](Advanced%20Lists/XOR%20Linked%20Lists%20:%20A%20Memory%20Efficient%20Doubly%20Linked%20Lists)

An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. A memory efficient version of Doubly Linked List can be created using only one space for address field with every node. This memory efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bitwise XOR operation to save space for one address. In the XOR linked list, instead of storing actual memory addresses, every node stores the XOR of addresses of previous and next nodes.
We can traverse the XOR list in both forward and reverse direction. While traversing the list we need to remember the address of the previously accessed node in order to calculate the next node’s address.

### Skip List

![Skip List](https://upload.wikimedia.org/wikipedia/commons/thumb/8/86/Skip_list.svg/470px-Skip_list.svg.png)

A skip list is a data structure that allows fast search within an ordered sequence of elements. Fast search is made possible by maintaining a linked hierarchy of subsequences, with each successive subsequence skipping over fewer elements than the previous one. Searching starts in the sparsest subsequence until two consecutive elements have been found, one smaller and one larger than or equal to the element searched for. Via the linked hierarchy, these two elements link to elements of the next sparsest subsequence, where searching is continued until finally we are searching in the full sequence. The elements that are skipped over may be chosen probabilistically or deterministically, with the former being more common.
Time complexity is `O(√n)`.

### Self Organizing List

A self-organizing list is a list that reorders its elements based on some self-organizing heuristic to improve average access time. The aim of a self-organizing list is to improve efficiency of linear search by moving more frequently accessed items towards the head of the list. A self-organizing list achieves near constant time for element access in the best case. A self-organizing list uses a reorganizing algorithm to adapt to various query distributions at runtime.
Following are different strategies used by Self Organizing Lists:

1. **Move-to-Front Method**: Any node searched is moved to the front. This strategy is easy to implement, but it may over-reward infrequently accessed items as it always move the item to front.

2. **Count Method**: Each node stores count of the number of times it was searched. Nodes are ordered by decreasing count. This strategy requires extra space for storing count.

3. **Transpose Method**: Any node searched is swapped with the preceding node. Unlike Move-to-front, this method does not adapt quickly to changing access patterns.

### Unrolled Linked List

![Unrolled Linked List](https://upload.wikimedia.org/wikipedia/commons/1/16/Unrolled_linked_lists_%281-8%29.PNG)

An unrolled linked list is a variation on the linked list which stores multiple elements in each node. That is, instead of storing single element at a node, unrolled linked lists store an array of elements at a node. It can dramatically increase cache performance, while decreasing the memory overhead associated with storing list metadata such as references. It is related to the `B-tree`.

#### Advantages:

- Because of the Cache behavior, linear search is much faster in unrolled linked lists.
- In comparison to ordinary linked list, it requires less storage space for pointers/references.
- It performs operations like insertion, deletion and traversal more quickly than ordinary linked lists (because search is faster).

#### Disadvantages:

- The overhead per node is comparatively high than singly linked lists.

## [Segment Tree](Segment%20Tree)

A segment tree is a tree data structure for storing intervals, or segments. It allows querying which of the stored segments contain a given point.It cannot be modified once built.  
A segment tree for a set I of n intervals uses `O(n log n)` storage and can be built in `O(n log n)` time. Segment trees support searching for all the intervals that contain a query point in `O(log n + k)`, k being the number of retrieved intervals or segments.

## [Trie](Trie)

Trie is an efficient information retrieval data structure. Using trie, search complexities can be brought to optimal limit (key length).  
Unlike a binary search tree, no node in the tree stores the key associated with that node; instead, its position in the tree defines the key with which it is associated. All the descendants of a node have a common prefix of the string associated with that node, and the root is associated with the empty string. Values are not necessarily associated with every node. Rather, values tend only to be associated with leaves, and with some inner nodes that correspond to keys of interest.  
If we store keys in binary search tree, a well balanced BST will need time proportional to `M * log N`, where M is maximum string length and N is number of keys in tree. Using trie, we can search the key in `O(M)` time. However the penalty is on trie storage requirements.

## [Binary Indexed Tree](Binary%20Indexed%20Tree)

![Binary Indexed Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/BITDemo.gif/200px-BITDemo.gif)

A **Fenwick tree** or binary indexed tree is a data structure that can efficiently update elements and calculate prefix sums in a table of numbers.  
When compared with a flat array of numbers, the Fenwick tree achieves a much better balance between two operations: element update and prefix sum calculation.  
Fenwick trees allow both operations to be performed in `O(log n)` time. This is achieved by representing the numbers as a tree, where the value of each node is the sum of the numbers in that subtree. 

## [Suffix Array and Suffix Tree](Suffix%20Array%20and%20Suffix%20Tree)

A suffix array is a sorted array of all suffixes of a string.  
A suffix tree (also called PAT tree or, in an earlier form, position tree) is a compressed trie containing all the suffixes of the given text as their keys and positions in the text as their values. Suffix trees allow particularly fast implementations of many important string operations.

## [Self-Balancing Binary Search Trees](Self-Balancing%20Binary%20Search%20Trees)

A self-balancing (or height-balanced) binary search tree is any node-based binary search tree that automatically keeps its height (maximal number of levels below the root) small in the face of arbitrary item insertions and deletions.

Unbalanced Tree
![](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a9/Unbalanced_binary_tree.svg/600px-Unbalanced_binary_tree.svg.png)  
The same tree after being height-balanced
![](https://upload.wikimedia.org/wikipedia/commons/thumb/0/06/AVLtreef.svg/800px-AVLtreef.svg.png)

### [AVL](Self-Balancing%20Binary%20Search%20Trees/AVL)

![](https://upload.wikimedia.org/wikipedia/commons/thumb/a/ad/AVL-tree-wBalance_K.svg/262px-AVL-tree-wBalance_K.svg.png)  
-AVL tree with balance factors 

In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take `O(log n)` time in both the average and worst cases, where n is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.  
For lookup-intensive applications, AVL trees are faster than red–black trees because they are more strictly balanced. Similar to red–black trees, AVL trees are height-balanced. Both are, in general, neither weight-balanced nor μ-balanced that is, sibling nodes can have hugely differing numbers of descendants.

### [Splay Tree](Self-Balancing%20Binary%20Search%20Trees/Splay%20Tree)

A splay tree is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again. It performs basic operations such as insertion, look-up and removal in `O(log n)` time. For many sequences of non-random operations, splay trees perform better than other search trees, even when the specific pattern of the sequence is unknown.

### [B Tree](Self-Balancing%20Binary%20Search%20Trees/B%20Tree)

![](https://upload.wikimedia.org/wikipedia/commons/thumb/6/65/B-tree.svg/400px-B-tree.svg.png)

A B-tree is a self-balancing tree data structure that keeps data sorted and allows searches, sequential access, insertions, and deletions in logarithmic time. The B-tree is a generalization of a binary search tree in that a node can have more than two children.  
Unlike self-balancing binary search trees, the B-tree is optimized for systems that read and write large blocks of data. B-trees are a good example of a data structure for external memory. It is commonly used in databases and filesystems.

##### Properties of B-Tree

- All leaves are at same level.
- A B-Tree is defined by the term minimum degree ‘t’. The value of t depends upon disk block size.
- Every node except root must contain at least t-1 keys. Root may contain minimum 1 key.
- All nodes (including root) may contain at most 2t – 1 keys.
- Number of children of a node is equal to the number of keys in it plus 1.
- All keys of a node are sorted in increasing order. The child between two keys k1 and k2 contains all keys in range from k1 and k2.
- B-Tree grows and shrinks from root which is unlike Binary Search Tree. Binary Search Trees grow downward and also shrink from downward.
- Like other balanced Binary Search Trees, time complexity to search, insert and delete is O(Logn)

### [Red Black Tree](Self-Balancing%20Binary%20Search%20Trees/Red%20Black%20Tree)

![](https://upload.wikimedia.org/wikipedia/commons/thumb/6/66/Red-black_tree_example.svg/500px-Red-black_tree_example.svg.png)

Each node of the binary tree has an extra bit, and that bit is often interpreted as the color (red or black) of the node. These color bits are used to ensure the tree remains approximately balanced during insertions and deletions.  
The root node is always black. There are no two adjacent red nodes (A red node cannot have a red parent or red child). Every path from root to a NULL node has same number of black nodes.  
**Black height** is number of black nodes on a path from a node to a leaf. Leaf nodes are also counted black nodes. A node of height h has `black-height >= h/2`.  
Every Red Black Tree with n nodes has `height <= 2Log2(n+1)`

## [K Dimensional Tree](K%20Dimensional%20Tree)

A K-D Tree(also called as K-Dimensional Tree) is a binary search tree where data in each node is a K-Dimensional point in space. In short, it is a space partitioning(details below) data structure for organizing points in a K-Dimensional space.  
A non-leaf node in K-D tree divides the space into two parts, called as half-spaces.  
Points to the left of this space are represented by the left subtree of that node and points to the right of the space are represented by the right subtree.  
k-d trees are a special case of binary space partitioning trees.

## [Disjoint Set](Disjoint%20Set)

A disjoint-set data structure, also called a union–find data structure or merge–find set, is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It provides near-constant-time operations (bounded by the inverse Ackermann function) to add new sets, to merge existing sets, and to determine whether elements are in the same set.

## [Persistent data structure](Persistent%20data%20structure)

A persistent data structure is a data structure that always preserves the previous version of itself when it is modified. Such data structures are effectively immutable, as their operations do not (visibly) update the structure in-place, but instead always yield a new updated structure.  
A data structure is partially persistent if all versions can be accessed but only the newest version can be modified. The data structure is fully persistent if every version can be both accessed and modified. If there is also a meld or merge operation that can create a new version from two previous versions, the data structure is called confluently persistent. Structures that are not persistent are called ephemeral.  
These types of data structures are particularly common in logical and [functional programming](https://en.wikipedia.org/wiki/Functional_programming), and in a purely functional program all data is immutable, so all data structures are automatically fully persistent.

## References

- [Geeks for Geeks](http://www.geeksforgeeks.org/advanced-data-structures)
- [Skip List](https://en.wikipedia.org/wiki/Skip_list)
- [Segment Tree](https://en.wikipedia.org/wiki/Segment_tree)
- [Suffix Tree](https://en.wikipedia.org/wiki/Suffix_tree)
