## Dynamic Programming

> Those who cannot remember past, are condemned to repeat it.    

Dynamic programming approach is similar to divide and conquer in breaking down the problem into smaller possible sub-problems. But unlike, divide and conquer, these sub-problems are not solved independently. Rather, results of these smaller sub-problems are remembered and used for similar or overlapping sub-problems.  

Mostly, these algorithms are used for optimization. Before solving the in-hand sub-problem, dynamic algorithm will try to examine the results of the previously solved sub-problems. The solutions of sub-problems are combined in order to achieve the best solution.  

So we can say that −

- The problem should be able to be divided into smaller overlapping sub-problem.

- An optimum solution can be achieved by using an optimum solution of smaller sub-problems.

- Dynamic algorithms use memorization.

In contrast to greedy algorithms, where local optimization is addressed, dynamic algorithms are motivated for an overall optimization of the problem.  

In contrast to divide and conquer algorithms, where solutions are combined to achieve an overall solution, dynamic algorithms use the output of a smaller sub-problem and then try to optimize a bigger sub-problem. Dynamic algorithms use memorization to remember the output of already solved sub-problems.  
Dynamic Programming solutions are faster than exponential brute method and can be easily proved for their correctness.

Following are the two main properties of a problem that suggest that the given problem can be solved using Dynamic programming.

1. Overlapping Subproblems
2. Optimal Substructure

### Overlapping Subproblems

There are two ways of doing this.
1. **Memorization** ***(Top-Down)*** : It is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. Start solving the given problem by breaking it down. If you see that the problem has been solved already, then just return the saved answer. If it has not been solved, solve it and save the answer. This is usually easy to think of and very intuitive.
2. **Tabulation** ***(Bottom-Up)*** : Analyze the problem and see the order in which the sub-problems are solved and start solving from the trivial subproblem, up towards the given problem. In this process, it is guaranteed that the subproblems are solved before solving the problem.

Both Tabulated and Memoized store the solutions of subproblems. In Memoized version, table is filled on demand while in Tabulated version, starting from the first entry, all entries are filled one by one. Unlike the Tabulated version, all entries of the lookup table are not necessarily filled in Memoized version.

### Optimal Substructure

A problem is said to have optimal substructure if an optimal solution can be constructed efficiently from optimal solutions of its subproblems. This property is used to determine the usefulness of dynamic programming and greedy algorithms for a problem.  
For example, the Shortest Path problem has following optimal substructure property:
If a node x lies in the shortest path from a source node u to destination node v then the shortest path from u to v is combination of shortest path from u to x and shortest path from x to v. The standard All Pair Shortest Path algorithms like Floyd–Warshall and Bellman–Ford are typical examples of Dynamic Programming. On the other hand, the Longest Path problem doesn’t have the Optimal Substructure property

## Advanced Concepts

- Bitmasking and Dynamic Programming
- Digital Dynamic Programming

## Example

The following computer problems can be solved using dynamic programming approach −

- Fibonacci number series
- Knapsack problem
- Tower of Hanoi
- All pair shortest path by Floyd-Warshall
- Shortest path by Dijkstra
- Project scheduling  

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Dynamic Programming](https://www.tutorialspoint.com/data_structures_algorithms/dynamic_programming.htm)
- [Introduction to Dynamic Programming](https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/)
