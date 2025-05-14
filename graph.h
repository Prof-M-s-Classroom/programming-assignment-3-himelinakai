#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"

class Graph {
public:
    Graph(int vertices) {
        // need v x v matrix
        int inf = INT_MAX;
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
        }

        for (int j = 0; j < numVertices; j++) {
            for (int m = 0; m < numVertices; m++) {
                adjMatrix[j][m] = inf;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;

    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        MinHeap heap(numVertices);

        // Insert vertex 0 into heap
        heap.insert(0,0);

        // Initialize the rest of the values of the heap
        for (int i = 0; i < numVertices; i++) {
            heap.insert(i, INT_MAX);
        }

        // Vertex 0 has key value of 0
        heap.decreaseKey(0, 0);

        int parent[numVertices];
        int child[numVertices];
        int weight[numVertices];

        // Initialize key values for first row
        for (int i = 1; i < numVertices; i++) {
            heap.decreaseKey(i, adjMatrix[0][i]);
            parent[i] = 0;
            child[i] = i;
            weight[i] = adjMatrix[0][i];
        }

        // Updates arrays (extract min and decrease key
        for (int i = 1; i < numVertices + 1; i++) {
            heap.extractMin();
            for (int j = i+1; j < numVertices; j++) {
                if (adjMatrix[i][j] < adjMatrix[i - 1][j]) {
                    heap.decreaseKey(j, adjMatrix[i][j]);
                    parent[j] = i;
                    child[j] = j;
                    weight[j] = adjMatrix[i][j];
                }
            }
        }

        int total_cost = 0;
        // Don't include first
        for (int i = 1; i < numVertices; i++) {
            std::cout << parent[i] << " -- " << child[i] << " (" << weight[i] << ")" << std::endl;
            total_cost += weight[i];
        }

        std::cout << "Total Cost: " << total_cost << std::endl;

    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif