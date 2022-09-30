The goal of the assignment is to implement a min-priority queue based on an “extended heap” data structure. Such a data
structure supports a priority queue when the priority of any element in the queue may change. The elements in the
extended heap have the following fields:
1. An id that uniquely identifies a contestant.
2. A contestant’s point total.
The asymptotic running time to find an element with id k in a regular heap containing n elements is O(n). Your extended
heap should be able to find a contestant with id k in O(1) time. Once a contestant node is found, its score can be changed
in O(lg n) time. You may assume that each contestant receives a unique integer id between 1 and n, and that the maximum
size n of the extended heap is given. To support find() in O(1) time, add a handle array---an additional array that tracks
the location of all the items in the extended heap. A contestant whose id is k resides in heap location handle[k]. When id k
is not in the extended heap, the handle should contain a value that cannot be a legal index into the heap. Note that when a
contestant’s location in the heap changes, your program must update the handle array accordingly. For this assignment,
indexing for all arrays starts with 1 (leave heap[0] and handle[0] unused).