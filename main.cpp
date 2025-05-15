#include <iostream>
#include "graph.h"
#include "heap.h"

int main() {

    /*

    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
*/

    Graph g(6);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 5, 8);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 5, 2);

    g.primMST();

    return 0;
}