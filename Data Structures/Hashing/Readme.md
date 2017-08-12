## Hashing

Hash Table is a data structure which stores data in an associative manner. In a hash table, data is stored in an array format, where each data value has its own unique index value. Access of data becomes very fast if we know the index of the desired data.  

For arrays and linked lists, we need to search in a linear fashion, which can be costly in practice. If we use arrays and keep the data sorted, then a phone number can be searched in O(Logn) time using Binary Search, but insert and delete operations become costly as we have to maintain sorted order.  

With balanced binary search tree, we get moderate search, insert and delete times. All of these operations can be guaranteed to be in O(Logn) time.  

Hashing is the solution that can be used in almost all such situations and performs extremely well compared to above data structures like Array, Linked List, Balanced BST in practice.  

**Hashing is an improvement over Direct Access Table.**  

```
In hashing, large keys are converted into small keys by using hash functions. The values are then stored in a data structure called hash table.
```
The idea of hashing is to distribute entries (key/value pairs) uniformly across an array. Each element is assigned a key (converted key). By using that key we can access the element in O(1) time.  
A good hash function should have following properties  

1. Efficiently computable.
2. Should uniformly distribute the keys (Each table position equally likely for each key)

## Collision resolution techniques

Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. The situation where a newly inserted key maps to an already occupied slot in hash table is called collision and must be handled using some collision handling technique.  

### Separate chaining ***(open hashing)***

It is usually implemented using linked lists. In separate chaining, each element of the hash table is a linked list. To store an element in the hash table you must insert it into a specific linked list. If there is any collision (i.e. two different elements have same hash value) then store both the elements in the same linked list.  
It is simpler to implement. As hash table nexer fills up, we can always add elements.  
If the chain becomes long, then search time can become O(n) in worst case. It uses extra space for links.

### Open Addressing ***(closed hashing)***

In open addressing, instead of in linked lists, all entry records are stored in the array itself. When a new entry has to be inserted, the hash index of the hashed value is computed and then the array is examined (starting with the hashed index). If the slot at the hashed index is unoccupied, then the entry record is inserted in slot at the hashed index else it proceeds in some probe sequence until it finds an unoccupied slot.  

The probe sequence is the sequence that is followed while traversing through entries. In different probe sequences, you can have different intervals between successive entry slots or probes.  

When searching for an entry, the array is scanned in the same sequence until either the target element is found or an unused slot is found. This indicates that there is no such key in the table. The name "open addressing" refers to the fact that the location or address of the item is not determined by its hash value.  

#### 1. Linear Probing

Linear probing is when the interval between successive probes is fixed (usually to 1). Let’s assume that the hashed index for a particular entry is index. The probing sequence for linear probing will be:

```
index = index % hashTableSize
index = (index + 1) % hashTableSize
index = (index + 2) % hashTableSize
index = (index + 3) % hashTableSize
```

#### 2. Quadratic Probing

Here, when the slot at a hashed index for an entry record is already occupied, you must start traversing until you find an unoccupied slot. The interval between slots is computed by adding the successive value of an arbitrary polynomial in the original hashed index.  

Let us assume that the hashed index for an entry is index and at index there is an occupied slot. The probe sequence will be as follows:

```
index = index % hashTableSize
index = (index + 1^2) % hashTableSize
index = (index + 2^2) % hashTableSize
index = (index + 3^2) % hashTableSize
```

#### 3. Double Hashing

Double hashing is similar to linear probing and the only difference is the interval between successive probes. Here, the interval between probes is computed by using two hash functions.

Let us say that the hashed index for an entry record is an index that is computed by one hashing function and the slot at that index is already occupied. You must start traversing in a specific probing sequence to look for an unoccupied slot. The probing sequence will be:

```
index = (index + 1 * indexH) % hashTableSize;
index = (index + 2 * indexH) % hashTableSize;
```

##### Comparison of above three:

Linear probing has the best cache performance, but suffers from clustering. One more advantage of Linear probing is easy to compute.  

Quadratic probing lies between the two in terms of cache performance and clustering.  

Double hashing has poor cache performance but no clustering. Double hashing requires more computation time as two hash functions need to be computed.  

## Applications

- **Associative arrays**: Hash tables are commonly used to implement many types of in-memory tables. They are used to implement associative arrays (arrays whose indices are arbitrary strings or other complicated objects).
- **Database indexing**: Hash tables may also be used as disk-based data structures and database indices (such as in dbm).
- **Caches**: Hash tables can be used to implement caches i.e. auxiliary data tables that are used to speed up the access to data, which is primarily stored in slower media.
- **Object representation**: Several dynamic languages, such as Perl, Python, JavaScript, and Ruby use hash tables to implement objects.

## Basic Operations

Following are the basic primary operations of a hash table.

- **Search** − Searches an element in a hash table.

- **Insert** − inserts an element in a hash table.

- **Delete** − Deletes an element from a hash table.

## References

- [Geeks For Geeks](geeksforgeeks.org)
- [Data Structure and Algorithms - Hash Table](https://www.tutorialspoint.com/data_structures_algorithms/hash_data_structure.htm)
- [Hash Tables](https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/)
