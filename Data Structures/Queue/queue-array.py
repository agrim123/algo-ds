"""
    Queue: Array Implementation
"""


class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        return self.items.pop()

    def front(self):
        return self.items[0]

    def rear(self):
        return self.items[self.size() - 1]

    def size(self):
        return len(self.items)


q = Queue()
q.enqueue(2)
q.enqueue(4)
q.enqueue(3)
q.dequeue()
print(q.rear())
