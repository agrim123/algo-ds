## Graph

Graphs are mathematical structures that represent pairwise relationships between objects. A graph is a flow structure that represents the relationship between various objects. It can be visualized by using the following two basic components:

**Nodes** : Nodes are entities whose relationships are expressed using edges. If a graph comprises 2 nodes A and B and an undirected edge between them, then it expresses a bi-directional relationship between the nodes and edge.

**Edges** : Edges are the components that are used to represent the relationships between various nodes in a graph. An edge between two nodes expresses a one-way or two-way relationship between the nodes.

> Unlike trees, graphs may contain cycles

#### Types of nodes

**Root node** : The root node is the ancestor of all other nodes in a graph. It does not have any ancestor. Each graph consists of exactly one root node. Generally, you must start traversing a graph from the root node.

**Leaf nodes** : In a graph, leaf nodes represent the nodes that do not have any successors. These nodes only have ancestor nodes. They can have any number of incoming edges but they will not have any outgoing edges.

### Types of Graphs

1. **Undirected** : An undirected graph is a graph in which all the edges are bi-directional i.e. the edges do not point in any specific direction.

```
 A ----- C
 |       |
 |       |
 B ----- D
```
2. **Directed** : A directed graph is a graph in which all the edges are uni-directional i.e. the edges point in a single direction.
```
 A -->-- C
 |       |
 ^       ^  
 |       |
 B -->-- D
```
3. **Weighted** : In a weighted graph, each edge is assigned a weight or cost.  
 Consider a graph of 4 nodes as in the diagram below. As you can see each edge has a weight/cost assigned to it. If you want to go from vertex 1 to vertex 3, you can take one of the following 3 paths:
```
1 -> 2 -> 3
1 -> 3
1 -> 4 -> 3
```
Therefore the total cost of each path will be as follows: - The total cost of 1 -> 2 -> 3 will be (1 + 2) i.e. 3 units - The total cost of 1 -> 3 will be 1 unit - The total cost of 1 -> 4 -> 3 will be (3 + 2) i.e. 5 units
```
        1
   A ------- C
   | \       |
   |  \      |
   |   \ 1   |
 3 |    \    |  2
   |     \   |
   |      \  |
   |       \ |
   B ------- D
        2
```
4. **Cyclic** : A graph is cyclic if the graph comprises a path that starts from a vertex and ends at the same vertex. That path is called a cycle. An acyclic graph is a graph that has no cycle.  

Following two are the most commonly used representations of graph.
1. Adjacency Matrix
2. Adjacency List

### Adjacency Matrix

An adjacency matrix is a `VxV` binary matrix A. Element `A[i][j]` is 1 if there is an edge from vertex i to vertex j else `A[i][j]` is 0.

### Adjacency List

An adjacency list is an array A of separate lists. Each element of the array Ai is a list, which contains all the vertices that are adjacent to vertex i. An array of linked lists is used.



## Basic Operations

- **Add Vertex** − Adds a vertex to the graph.

- **Add Edge** − Adds an edge between the two vertices of the graph.

- **Display Vertex** − Displays a vertex of the graph.

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
- [Data Structure and Algorithms - Graph](https://www.tutorialspoint.com/data_structures_algorithms/graph_data_structure.htm)
- [Graph Representation](https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/)
