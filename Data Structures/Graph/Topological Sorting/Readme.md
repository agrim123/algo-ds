## Topological Sorting

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.  
For instance, the vertices of the graph may represent tasks to be performed, and the edges may represent constraints that one task must be performed before another; in this application, a topological ordering is just a valid sequence for the tasks. 

> In order to have a topological sorting the graph must not contain any cycles

### Algorithms

1. Kahn’s algorithm

## References

- [Geeks For Geeks](http://www.geeksforgeeks.org/topological-sorting/)
- [Topological Sort](https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/tutorial/)
