#ifndef GRAPH_H
#define GRAPH_H
//using std namespace;

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
        delete[] adjMatrix;
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void primMST()  // Must print MST edges and total weight
    {
        // create heap of size vertices
        // if element is adj, insert in heap

        // while heap array is not empty
            // extract min
            // whatever is at pos 1 becomes new root, make sure new positions are updated
            // update keys
            // minheapify
    }

    void print() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjMatrix[i][j] << " " << std::endl;
            }
        }
    }

private:
    int** adjMatrix;
    int numVertices;
};

#endif