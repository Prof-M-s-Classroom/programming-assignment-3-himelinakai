[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Melina Kai Kwarcinski

## Description
This program uses a min heap in order to implement Prim's Algorithm to find the MST of a given graph.
The graph is stored as an adjacency matrix, and the vertices are ordered by key value in the min heap.
The min heap is implemented via three arrays: a vertex array, a key array and a position array. 

## Files
- graph.h
- heap.h
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logN)         |
| Extract Min          | O(logN)         |
| Decrease Key         | O(logN)         |
| Prim’s MST Overall   | O(V^2)          |

Insertion requires upheaping in the event that the newest vertex is smaller than its ancestors. Upheaping has
a time complexity of O(logn). 

Extracting the minimum runs to O(logn) because it requires downheaping if the new node is not the smallest vertex.
Accessing the minimum itself is O(1).

Decreasing the key requires potential upheaping since the decreased key may now be smaller than its ancestors'. The
time complexity of upheaping is O(logn).

Because of the use of an adjacency matrix, the time complexity of PrimMST is O(V^2). 

## Test Case Description

Test #1

Input:

    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);


Output:

    0 -- 1 (2)
    1 -- 2 (3)
    0 -- 3 (6)
    1 -- 4 (5)
    Total Cost: 16

Test #2

Input:

    Graph g(6);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 5, 8);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 5, 2);

Output:

    0 -- 2 (2)
    2 -- 3 (1)
    3 -- 5 (2)
    0 -- 1 (3)
    2 -- 4 (4)
    Total Cost: 12


