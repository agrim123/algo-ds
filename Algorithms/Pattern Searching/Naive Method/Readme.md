# Naive Method

Slide the pattern over text one by one and check for a match. If a match is found, then slide by 1 again to check for subsequent matches.  

The number of comparisons in best case is `O(n)`  
Worst Case Scenarios (Number of comparisons in worst case is `O(m*(n-m+1)))`  
- All characters of the text and pattern are same
- When only the last character is different
