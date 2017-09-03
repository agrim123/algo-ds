"""
    Detect cycle in a graph
"""

from collections import defaultdict


class Graph():
    def __init__(self, vertices):
        self.graph = defaultdict(list)
        self.V = vertices

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def isCyclicUtil(self, v, visited, recursionStack):
        # Mark current node as visited and adds to recursion stack
        visited[v] = True
        recursionStack[v] = True

        # Recur for all neighbours if any neighbour is visited and in recursionStack then graph is cyclic
        for n in self.graph[v]:
            if visited[n] is False:
                if self.isCyclicUtil(n, visited, recursionStack) is True:
                    return True
            elif recursionStack[n] is True:
                return True

        # The node needs to be poped from recursion stack before function ends
        recursionStack[v] = False
        return False

    def isCyclic(self):
        visited = [False] * self.V
        recursionStack = [False] * self.V
        for node in range(self.V):
            if visited[node] is False:
                if self.isCyclicUtil(node, visited, recursionStack) is True:
                    return True
        return False


g = Graph(4)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

if g.isCyclic() == 1:
    print("Graph contains cycle")
else:
    print("Graph doesn't contain cycle")
