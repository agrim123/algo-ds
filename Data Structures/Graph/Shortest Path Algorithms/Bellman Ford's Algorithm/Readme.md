## Bellman Ford's Algorithm

Bellman Ford's algorithm is used to find the shortest paths from the source vertex to all other vertices in a weighted graph. It depends on the following concept: Shortest path contains at most n−1 edges, because the shortest path couldn't have a cycle.   
Algorithm Steps: 

- The outer loop traverses from 0 : n−1.
- Loop over all edges, check if the next node distance > current node distance + edge weight, in this case update the next node distance to "current node distance + edge weight".

Time Complexity of Bellman Ford algorithm is relatively high `O(V⋅E)`.
