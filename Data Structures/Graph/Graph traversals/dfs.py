# Breath First Search

from collections import defaultdict


class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, x, y):
        self.graph[x].append(y)

    def DepthFirstSearchUtil(self, v, visited):
        visited[v] = True
        print(v)
        for i in self.graph[v]:
            if visited[i] is False:
                self.DepthFirstSearchUtil(i, visited)

    def DepthFirstSearch(self, s):
        visited = [False]*(len(self.graph))
        self.DepthFirstSearchUtil(s, visited)


g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

print("Depth First Traversal (starting from vertex 2) n")
g.DepthFirstSearch(2)
