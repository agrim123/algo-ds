## Dijkstra's Algorithm

![Dijkstra's Algorithm](https://upload.wikimedia.org/wikipedia/commons/5/57/Dijkstra_Animation.gif)

Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks.

Dijkstra’s algorithm solves the single-source shortest-paths problem on a weighted,
directed graph G = (V, E) for the case in which all edge weights are nonnegative.

### Algorithm Steps:

- Set all vertices distances = infinity except for the source vertex, set the source distance = 0.
- Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
- Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
- Update the distances of the connected vertices to the popped vertex in case of "current vertex distance + edge weight < next vertex distance", then push the vertex with the new distance to the priority queue.
- If the popped vertex is visited before, just continue without using it.
- Apply the same algorithm again until the priority queue is empty.

Time Complexity of Dijkstra's Algorithm is `O(V^2)` but with min-priority queue it drops down to `O(V+ElogV)`.  

With a good implementation, the running time of Dijkstra’s algorithm is lower than that of the Bellman-Ford algorithm
