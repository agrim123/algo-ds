## Priority Queue

Priority Queue is an extension of queue with following properties.

1) Every item has a priority associated with it.
2) An element with high priority is dequeued before an element with low priority.
3) If two elements have the same priority, they are served according to their order in the queue.

Or,   
A Priority Queue is different from a normal queue, because instead of being a “first-in-first-out”, values come out in order by priority. It is an abstract data type that captures the idea of a container whose elements have “priorities” attached to them. An element of highest priority always appears at the front of the queue. If that element is removed, the next highest priority element advances to the front.

## Implementing Priority Queues

1) Using arrays
2) Using heaps (Majorly used)

## Applications

- CPU Scheduling, Disk Scheduling.
- Graph algorithms like [Dijkstra’s Shortest Path](/Data%20Structures/Graph/Shortest%20Path%20Algorithms/Dijkstra%27s%20Algorithm) and [Prim’s Minimum Spanning Tree](/Data%20Structures/Graph/Spanning%20Tree/Prim%E2%80%99s%20Algorithm), etc.
- Data Compression.
- Load balancing, interrupt handling.
- All queue applications where priority is involved.
