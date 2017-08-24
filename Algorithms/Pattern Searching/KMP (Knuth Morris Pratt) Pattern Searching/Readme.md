# KMP (Knuth Morris Pratt) Pattern Searching

The KMP string searching algorithm searches for occurrences of a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.  

Worst case complexity is `O(n)`

## References

- http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
