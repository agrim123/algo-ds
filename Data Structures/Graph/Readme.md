# Graph

Graphs are mathematical structures that represent pairwise relationships between objects. A graph is a flow structure that represents the relationship between various objects. It can be visualized by using the following two basic components:

**Nodes** : Nodes are entities whose relationships are expressed using edges. If a graph comprises 2 nodes A and B and an undirected edge between them, then it expresses a bi-directional relationship between the nodes and edge.

**Edges** : Edges are the components that are used to represent the relationships between various nodes in a graph. An edge between two nodes expresses a one-way or two-way relationship between the nodes.

> Unlike trees, graphs may contain cycles

### Types of nodes

**Root node** : The root node is the ancestor of all other nodes in a graph. It does not have any ancestor. **Each graph consists of exactly one root node**. Generally, we must start traversing a graph from the root node.

**Leaf nodes** : In a graph, leaf nodes represent the nodes that do not have any successors. **These nodes only have ancestor nodes**. They can have any number of incoming edges but they will not have any outgoing edges.

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
 Consider a graph of 4 nodes as in the diagram below. As we can see each edge has a weight/cost assigned to it. If we want to go from vertex 1 to vertex 3, we can take one of the following 3 paths:
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

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Graph](https://www.tutorialspoint.com/data_structures_algorithms/graph_data_structure.htm)
- [Graph Representation](https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/tutorial/)
