## Doubly Linked Lists

```
+------+-----+-----+     +-----+-----+-----+     +-----+-----+------+
| NULL |  1  |  o  ------>  p  |  2  |  o ------->  p  |  3  | NULL |
+------+-----+-----+     +-----+-----+-----+     +-----+-----+------+

```

Doubly Linked List is a variation of Linked list in which navigation is possible in both ways, either forward and backward easily as compared to Single Linked List. Following are the important terms to understand the concept of doubly linked list.

- Link − Each link of a linked list can store a data called an element.

- Next − Each link of a linked list contains a link to the next link called Next.

- Prev − Each link of a linked list contains a link to the previous link called Prev.

- LinkedList − A Linked List contains the connection link to the first link called First and to the last link called Last.

## Advantages

Double-linked lists require more space per node (unless one uses XOR-linking), and their elementary operations are more expensive; but they are often easier to manipulate because they allow fast and easy sequential access to the list in both directions. In a doubly linked list, one can insert or delete a node in a constant number of operations given only that node's address. To do the same in a singly linked list, one must have the address of the pointer to that node, which is either the handle for the whole list (in case of the first node) or the link field in the previous node. Some algorithms require access in both directions. On the other hand, doubly linked lists do not allow tail-sharing and cannot be used as persistent data structures.

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Doubly Linked List](http://www.geeksforgeeks.org/doubly-linked-list/)
- https://en.wikipedia.org/wiki/Linked_list
