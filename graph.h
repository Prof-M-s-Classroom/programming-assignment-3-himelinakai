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
        // Must print MST edges and total weight
       bool inMST[numVertices]; // Array holding vertices in MST
       int key[numVertices]; // Array storing key values
       int parent[numVertices]; // Array storing parent indexes

        // Start with arrays empty - no vertices in MST yet
       for (int i = 0; i < numVertices; i++) {
           key[i] = INT_MAX;
           inMST[i] = false;
       }

       key[0] = 0;  // Want vertex 0 to be starting point
       parent[0] = -1;


       cout << "Edges in the MST:" << endl;
       int total_cost = 0;

       for (int count = 0; count < numVertices; count++) {
           // Find minimum key from unvisited vertices
           int u = -1;
           int min = INT_MAX;
           for (int v = 0; v < numVertices; v++) {
               if (!inMST[v] && key[v] < min) {
                   min = key[v];
                   u = v;
               }
           }

           if (u == -1) {
               break; // No valid vertex
           }


           // Add picked vertex to the MST
           inMST[u] = true;

           // Print the edge that was just added to MST
           if (parent[u] != -1) {
               cout << parent[u] << " -- " << u << " (" << adjMatrix[parent[u]][u] << ")" << endl;
               total_cost += adjMatrix[parent[u]][u];
           }

           // Update key value and parent index of the adjacent vertices
           for (int v = 0; v < numVertices; v++) {
               if (adjMatrix[u][v] != 0 && !inMST[v] && adjMatrix[u][v] < key[v]) {
                   parent[v] = u;
                   key[v] = adjMatrix[u][v];
               }
           }
       }

       cout << "Total Cost: " << total_cost << endl;
    }


private:
    int** adjMatrix;
    int numVertices;
};

#endif