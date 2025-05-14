[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Melina Kai Kwarcinski

## Description
Briefly describe what your program does and how the code is structured.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logn)         |
| Extract Min          | O(logn)         |
| Decrease Key         | O(logn)         |
| Prim’s MST Overall   | O(n logn)       |

Insertion requires upheaping in the event that the newest vertex is smaller than its ancestors. Upheaping has
a time complexity of O(logn). 

Extracting the minimum runs to O(logn) because it requires downheaping if the new node is not the smallest vertex.
Accessing the minimum itself is O(1).

Decreasing the key requires potential upheaping since the decreased key may now be smaller than its ancestors'. The
time complexity of upheaping is O(logn).



## Test Case Description

Input:  