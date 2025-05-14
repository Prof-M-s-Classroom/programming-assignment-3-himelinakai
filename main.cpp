#include <iostream>
#include "graph.h"
#include "heap.h"

int main() {

    /*
    MinHeap heap(5);
    heap.insert(2, 5);
    heap.insert(7, 7);
    heap.insert(4, 1);
    heap.insert(1, 0);
    heap.print();

    std::cout << std::endl;
    int test = heap.extractMin();
    heap.print();
    */

    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.print();

    /*
    g.primMST();
    */
    return 0;
}