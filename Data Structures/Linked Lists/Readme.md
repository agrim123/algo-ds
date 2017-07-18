# Linked Lists

A linked list is a sequence of data structures, which are connected together via links.

## Types of Linked List

- **Simple Linked List** − Item navigation is forward only.

- **Doubly Linked List** − Items can be navigated forward and backward.

- **Circular Linked List** − Last item contains link of the first element as next and the first element has a link to the last element as previous.

# Single Linked Lists


```
+-----+-----+     +-----+-----+     +-----+------+
|  1  |  n ---->  |  2  |  n ---->  |  3  | NULL |
+-----+-----+     +-----+-----+     +-----+------+

```

Linked List is a sequence of links which contains items. Each link contains a connection to another link. Linked list is the second most-used data structure after array. Following are the important terms to understand the concept of Linked List.

- Link − Each link of a linked list can store a data called an element.

- Next − Each link of a linked list contains a link to the next link called Next.

- LinkedList − A Linked List contains the connection link to the first link called First.

## Basic Operations

- **Insertion** − Adds an element at the beginning of the list.

- **Deletion** − Deletes an element at the beginning of the list.

- **Display** − Displays the complete list.

- **Search** − Searches an element using the given key.

- **Delete** − Deletes an element using the given key.

# Doubly Linked Lists

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


## Basic Operations

- **Insertion** − Adds an element at the beginning of the list.

- **Deletion** − Deletes an element at the beginning of the list.

- **Insert Last** − Adds an element at the end of the list.

- **Delete Last** − Deletes an element from the end of the list.

- **Insert After** − Adds an element after an item of the list.

- **Delete** − Deletes an element from the list using the key.

- **Display forward** − Displays the complete list in a forward manner.

- **Display backward** − Displays the complete list in a backward manner.


## Advantages over Arrays

1) Dynamic Size
2) Ease of insertion/deletion of elements

## Drawbacks

1) Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do binary search with linked lists.
2) Extra memory space for a pointer is required with each element of the list.


## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Linked List](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)