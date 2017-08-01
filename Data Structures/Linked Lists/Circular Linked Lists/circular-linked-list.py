"""
    Circular Linked List
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def push(self, new_data):
        ptr = Node(new_data)
        temp = self.head
        ptr.next = self.head

        if self.head is not None:
            while(temp.next != self.head):
                temp = temp.next
            temp.next = ptr
        else:
            ptr.next = ptr
        self.head = ptr

    def printList(self):
        temp = self.head
        if self.head is not None:
            while(True):
                print("%d" % (temp.data))
                temp = temp.next
                if (temp == self.head):
                    break


if __name__ == '__main__':
    llist = CircularLinkedList()
    llist.push(7)
    llist.push(1)
    llist.push(8)
    print(llist.printList())
