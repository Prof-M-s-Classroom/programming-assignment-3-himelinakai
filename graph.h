#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"
using namespace std;

class Graph {
public:
    Graph(int vertices) {
        // need v x v matrix
        int inf = INT_MAX;
        numVertices = vertices;
        adjMatrix = new int*[numVertices];

        // adjMatrix is an array of arrays, so need to initialize an array for each vertex
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
        }

        // Mark vertices as not adjacent by default, so initialize with INF
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

    // Graph is undirected, set edge between two vertices to key value
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST() {
        int* parent = new int[numVertices];  // Store MST
        int* key = new int[numVertices];     // Store keys


        MinHeap heap(numVertices);


        // Initialize all key values to INF and vertex values to -1
        for (int i = 0; i < numVertices; i++) {
            key[i] = INT_MAX;
            parent[i] = -1;
        }


        key[0] = 0; // Start at vertex 0


        // Insert all vertices into the min heap
        for (int v = 0; v < numVertices; v++) {
            heap.insert(v, key[v]);
        }


        int totalWeight = 0;
        cout << "Edges in the MST: " << endl;


        while (!heap.isEmpty()) {
            int u = heap.extractMin();


            // Print edge when it's added to the MST
            if (parent[u] != -1) {
                cout << parent[u] << " -- " << u << " (" << adjMatrix[u][parent[u]] << ")" << endl;
                totalWeight += adjMatrix[u][parent[u]];
            }

            // Update adjacent vertices
            for (int v = 0; v < numVertices; v++) {
                int weight = adjMatrix[u][v];
                if (weight != INT_MAX && heap.isInMinHeap(v) && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    heap.decreaseKey(v, weight);
                }
            }
        }


        cout << "Total Cost: " << totalWeight << endl;


        delete[] parent;
        delete[] key;
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif