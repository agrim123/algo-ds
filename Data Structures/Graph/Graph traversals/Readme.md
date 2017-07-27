## Graph traversals

Graph traversal means visiting every vertex and edge exactly once in a well-defined order. While using certain graph algorithms, you must ensure that each vertex of the graph is visited exactly once. The order in which the vertices are visited are important and may depend upon the algorithm or question that you are solving.

During a traversal, it is important that you track which vertices have been visited. The most common way of tracking vertices is to mark them.

### Breadth First Search (BFS)
![BFS](https://upload.wikimedia.org/wikipedia/commons/4/46/Animated_BFS.gif)  
BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.

As the name BFS suggests, you are required to traverse the graph breadthwise as follows:

- First move horizontally and visit all the nodes of the current layer
- Move to the next layer

#### Applications of BFS
- Shortest Path and Minimum Spanning Tree for unweighted graph
- P2P Networks
- Crawlers in search engines
- GPS
- Ford–Fulkerson algorithm 
- Test if a graph is [bipartite](https://en.wikipedia.org/wiki/Bipartite_graph)
- Finding all nodes within one connected component

### Depth First Search (DFS)

The DFS algorithm is a recursive algorithm that uses the idea of backtracking. It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.

Here, the word backtrack means that when you are moving forward and there are no more nodes along the current path, you move backwards on the same path to find nodes to traverse. All the nodes will be visited on the current path till all the unvisited nodes have been traversed after which the next path will be selected.

This recursive nature of DFS can be implemented using stacks.   
The basic idea is as follows:
- Pick a starting node and push all its adjacent nodes into a stack.
- Pop a node from stack to select the next node to visit and push all its adjacent nodes into a stack.
- Repeat this process until the stack is empty. However, ensure that the nodes that are visited are marked. This will prevent you from visiting the same node more than once. If you do not mark the nodes that are visited and you visit the same node more than once, you may end up in an infinite loop.  

Consider a tree 
```
                A
              /   \
             B     C
           /   \
          D     E
```
DFS works as : 
```
A
A -> B
A -> B -> D
A -> B -> D -> E
A -> B -> D -> E -> C
```
Time complexity is `O(V + E)`, when implemented using an adjacency list.

#### Applications of DFS
- Detecting cycle in a graph
- Path finding 
- Test if a graph is [bipartite](https://en.wikipedia.org/wiki/Bipartite_graph)
- Finding [Strongly Connected Components of a graph](https://en.wikipedia.org/wiki/Strongly_connected_component) : A directed graph is called strongly connected if there is a path from each vertex in the graph to every other vertex.

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Breadth First Search](https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/)
- [Depth First Search](https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/)
