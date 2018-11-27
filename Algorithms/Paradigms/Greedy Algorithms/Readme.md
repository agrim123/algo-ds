# Greedy Algorithms

Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. Greedy algorithms are used for optimization problems. An optimization problem can be solved using Greedy if the problem has the following property: At every step, we can make a choice that looks best at the moment, and we get the optimal solution of the complete problem. The Greedy algorithm has only one shot to compute the optimal solution so that it never goes back and reverses the decision.

## Where to use Greedy algorithms?

A problem must comprise these two components for a greedy algorithm to work:

1. It has optimal substructures. The optimal solution for the problem contains optimal solutions to the sub-problems.

2. It has a greedy property (hard to prove its correctness!). If we make a choice that seems the best at the moment and solve the remaining sub-problems later, we still reach an optimal solution. We will never have to reconsider our earlier choices.

## Some standard algorithms that are Greedy algorithms

1. **Kruskal's Minimum Spanning Tree (MST)**  
   - It is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two trees in the forest.
2. **Prim's Minimum Spanning Tree**  
   - We create a MST by picking edges one by one. We maintain two sets: set of the vertices already included in MST and the set of the vertices not yet included. The Greedy Choice is to pick the smallest weight edge that connects the two sets.
3. **Dijkstra's Shortest Path**  
   - It is very similar to Prim’s algorithm. The shortest path tree is built up, edge by edge. We maintain two sets: set of the vertices already included in the tree and the set of the vertices not yet included. The Greedy Choice is to pick the edge that connects the two sets and is on the smallest weight path from source to the set that contains not yet included vertices.
4. **[Huffman Coding](Huffman%20Encoding%20Decoding)**  
   - Huffman Coding is a loss-less compression technique. It assigns variable length bit codes to different characters. The Greedy Choice is to assign least bit length code to the most frequent character.
5. **Travelling Salesman Problem**  
   - "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city?" It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science.
6. **[Activity Selection Problem](Activity%20Selection%20Problem)**

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Greedy Algorithms](https://www.tutorialspoint.com/data_structures_algorithms/greedy_algorithms.htm)
