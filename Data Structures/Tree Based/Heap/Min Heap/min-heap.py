from heapq import heappush, heappop


class MinHeap:
    def __init__(self):
        self.heap = []

    def parent(self, i):
        return (i - 1)/2

    def insert_key(self, key):
        heappush(self.heap, key)

    def decrease_key(self, i, new_key):
        self.heap[i] = new_key
        while (i != 0 and self.heap[self.parent(i)] > self.heap[i]):
            self.heap[i], self.heap[self.parent(i)] = (
                self.heap[self.parent(i)], self.heap[i])

    def extract_min(self):
        return heappop(self.heap)

    def delete_key(self, i):
        self.decrease_key(i, float("-inf"))
        self.extract_min()

    def get_min(self):
        return self.heap[0]

h = MinHeap()
h.insert_key(3)
h.insert_key(2)
h.delete_key(1)
h.insert_key(15)
h.insert_key(5)
h.insert_key(4)
h.insert_key(45)

print(h.extract_min())
print(h.get_min())
h.decrease_key(2, 1)
print(h.get_min())
