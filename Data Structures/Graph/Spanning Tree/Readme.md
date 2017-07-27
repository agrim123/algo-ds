## Spanning Tree

A spanning tree T of an undirected graph G is a subgraph that is a tree which includes all of the vertices of G, with minimum possible number of edges. In general, a graph may have several spanning trees, but a graph that is not connected will not contain a spanning tree. If all of the edges of G are also edges of a spanning tree T of G, then G is a tree and is identical to T (that is, a tree has a unique spanning tree and it is itself).

### Minimum Spanning Tree

The cost of the spanning tree is the sum of the weights of all the edges in the tree. There can be many spanning trees. Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees. There also can be many minimum spanning trees.

#### Applications of Minimum Spanning Tree
- Network design
- Approximation algorithms for NP-hard problems
   - Traveling salesperson problem
   - [Steiner tree](http://www.geeksforgeeks.org/steiner-tree/)
- Cluster analysis
- Image segmentation

#### Algorithms to solve Minimum Spanning Tree Problem

1. **Kruskal’s Algorithm**
   - Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. Kruskal's algorithm follows greedy approach as in each iteration it finds an edge which has least weight and add it to the growing spanning tree.
   - Time Complexity: Most time consuming operation is sorting because the total complexity of the Disjoint-Set operations will be `O(ElogV)` and this is overall Time Complexity of the algorithm.
2. **Prim’s Algorithm**
   - Prim’s Algorithm also uses Greedy approach to find the minimum spanning tree. In Prim’s Algorithm we grow the spanning tree from a starting position. Unlike an edge in Kruskal's, we add vertex to the growing spanning tree in Prim's.
   - Time Complexity: The time complexity is `O((V+E)logV)` because each vertex is inserted in the priority queue only once and insertion in priority queue take logarithmic time.

## References

- http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
- http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
- [Minimum Spanning Tree](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/)
