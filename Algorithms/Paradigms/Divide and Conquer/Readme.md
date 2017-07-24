## Divide and Conquer

In this approach the problem is broken into smaller subproblems of same type and each of this subproblem is then solved independently. The solution of all subproblems are merged to obtain solution of original problem.

## Examples

Following algorithms are based on `Divide and Conquer approach`

1. Merge Sort
2. Quick Sort
3. Binary Search
4. Strassen's Matrix Multiplication
   - Efficient Algorithm for multiplying two matrices.
   - A simple method to multiply two matrices need 3 nested loops and is `O(n^3)`. Strassen’s algorithm multiplies two matrices in `O(n^2.8974)` time.
   - [Easy way to remember](http://www.geeksforgeeks.org/easy-way-remember-strassens-matrix-equation/)
5. Closest pair (points)
   - It is a problem of computational geometry: given n points in metric space, find a pair of points with the smallest distance between them.
   - The problem can be solved in `O(n^2)` time by calculating distances of every pair of points and comparing the distances to find the minimum. 
   - The Divide and Conquer algorithm solves the problem in `O(nLogn)` time.
6. Cooley–Tukey Fast Fourier Transform (FFT) algorithm
7. Karatsuba algorithm
   - It is a fast multiplication algorithm
   - It reduces the multiplication of two n-digit numbers to at most  `n^(log_{2}3) = n^(1.585)` single-digit multiplications in general. It is therefore faster than the classical algorithm, which requires `n^2` single-digit products.
8. [Writing our own pow(x,n) to calculate x^n](http://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/)
9. [Counting Inversions](http://www.geeksforgeeks.org/counting-inversions/)

### Divide and Conquer vs Dynamic Programming

Both paradigms divide the given problem into subproblems and solve subproblems. Divide and Conquer should be used when same subproblems are not evaluated many times. Otherwise Dynamic Programming or Memoization should be used. For example, Binary Search is a Divide and Conquer algorithm, we never evaluate the same subproblems again. On the other hand, for calculating nth Fibonacci number, Dynamic Programming should be preferred.

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Divide and Conquer](https://www.tutorialspoint.com/data_structures_algorithms/divide_and_conquer.htm)
