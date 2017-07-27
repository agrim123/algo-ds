## Shortest Path Algorithms

The shortest path problem is about finding a path between 2 vertices in a graph such that the total sum of the edges weights is minimum. 

### Bellman Ford's Algorithm

Bellman Ford's algorithm is used to find the shortest paths from the source vertex to all other vertices in a weighted graph. It depends on the following concept: Shortest path contains at most n−1 edges, because the shortest path couldn't have a cycle.   
Algorithm Steps: 

- The outer loop traverses from 0 : n−1.
- Loop over all edges, check if the next node distance > current node distance + edge weight, in this case update the next node distance to "current node distance + edge weight".

Time Complexity of Bellman Ford algorithm is relatively high `O(V⋅E)`.

### Dijkstra's Algorithm

Algorithm Steps:

- Set all vertices distances = infinity except for the source vertex, set the source distance = 0.
- Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
- Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
- Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex with the new distance to the priority queue.
- If the popped vertex is visited before, just continue without using it.
- Apply the same algorithm again until the priority queue is empty.

Time Complexity of Dijkstra's Algorithm is `O(V^2)` but with min-priority queue it drops down to `O(V+ElogV)`.

### Floyd Warshall's Algorithm

Floyd–Warshall's Algorithm is used to find the shortest paths between between all pairs of vertices in a graph, where each edge in the graph has a weight which is positive or negative.  
Time Complexity of Floyd–Warshall's Algorithm is `O(V^3)`, where V is the number of vertices in a graph.

## References

- [Geeks For Geeks](http://www.geeksforgeeks.org/graph-data-structure-and-algorithms/)
- [Shortest Path Algorithms](https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/tutorial/)
