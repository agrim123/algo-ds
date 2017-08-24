# Rabin-Karp Algorithm

It uses hashing to find any one of a set of pattern strings in a text. For text of length n and p patterns of combined length m, its average and best case running time is `O(n+m)` in space `O(p)`, but its worst-case time is `O(nm)`.  
Since we need to efficiently calculate hash values for all the substrings of size m of text, we must have a hash function which has following property.  
Hash at the next shift must be efficiently computable from the current hash value and next character in text or we can say hash(txt[s+1 .. s+m]) must be efficiently computable from `hash(txt[s .. s+m-1])` and `txt[s+m]` i.e., `hash(txt[s+1 .. s+m]) = rehash(txt[s+m], hash(txt[s .. s+m-1])` and rehash must be `O(1)` operation.  
The hash function suggested by Rabin and Karp calculates an integer value. The integer value for a string is numeric value of a string.  
To do rehashing, we need to take off the most significant digit and add the new least significant digit for in hash value.  
Rehashing is done using the following formula.
```
hash( txt[s+1 .. s+m] ) = d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q

hash( txt[s .. s+m-1] ) : Hash value at shift s.
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
d: Number of characters in the alphabet
q: A prime number
h: d^(m-1)
```

## References

- http://www.geeksforgeeks.org/searching-for-patterns-set-3-rabin-karp-algorithm/
