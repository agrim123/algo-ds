# Circular Linked Lists

```
head
|-->
   +------+-----+-----+     +-----+-----+-----+     +-----+-----+------+
 -->-- p  |  1  |  o  ------>  p  |  2  |  o ------->  p  |  3  |  o -->--
|  +------+-----+-----+     +-----+-----+-----+     +-----+-----+------+ |
 --------<----------------------------------------<-----------------------

```
Circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end. A circular linked list can be a singly circular linked list or doubly circular linked list. It is useful for implementation of queue.

## Advantages

A circularly linked list may be a natural option to represent arrays that are naturally circular, e.g. the corners of a polygon, a pool of buffers that are used and released in FIFO ("first in, first out") order, or a set of processes that should be time-shared in round-robin order. In these applications, a pointer to any node serves as a handle to the whole list.  

With a circular list, a pointer to the last node gives easy access also to the first node, by following one link. Thus, in applications that require access to both ends of the list (e.g., in the implementation of a queue), a circular structure allows one to handle the structure by a single pointer, instead of two.  

A circular list can be split into two circular lists, in constant time, by giving the addresses of the last node of each piece. The operation consists in swapping the contents of the link fields of those two nodes. Applying the same operation to any two nodes in two distinct lists joins the two list into one. This property greatly simplifies some algorithms and data structures, such as the quad-edge and face-edge.  

The simplest representation for an empty circular list (when such a thing makes sense) is a null pointer, indicating that the list has no nodes. Without this choice, many algorithms have to test for this special case, and handle it separately. By contrast, the use of null to denote an empty linear list is more natural and often creates fewer special cases.

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Circular Linked List](http://www.geeksforgeeks.org/circular-linked-list/)
- https://en.wikipedia.org/wiki/Linked_list
