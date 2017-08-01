# Double Linked List


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoubleLinkedList:
    def __init__(self):
        self.head = None

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        if self.head is not None:
            self.head.prev = new_node

        self.head = new_node

    def insertAfter(self, prev_node, data):
        if prev_node is None:
            print('Not Possible')
            return

        new_node = Node(data)
        new_node.next = prev_node.next
        prev_node.next = new_node
        new_node.prev = prev_node
        if new_node.next is not None:
            new_node.next.prev = new_node

    def printList(self, node):
        while(node is not None):
            print "%d" %(node.data),
            last = node
            node = node.next


if __name__ == '__main__':
    dllist = DoubleLinkedList()
    dllist.push(1)
    dllist.push(12)
    dllist.push(114)
    dllist.insertAfter(dllist.head.next, 8)
    print(dllist.printList(dllist.head))
