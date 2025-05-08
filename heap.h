#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        capacity = capacity;
        size = 0;

        heapArray[capacity];
        keyArray[capacity];
        position[capacity];
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }
    void insert(int vertex, int key) {
        if (size >= capacity) {
            return;
        }

        // insert the vertex at the end of the arr
            // if isInMinHeap() aka vertex exists, do not add
        // minheapify to move to correct spot

        if (!isInMinHeap(vertex)) {
            heapArray[size] = vertex;
            keyArray[size] = key;
            position[size] = size;
            minHeapify(size);
            size++;
        }
    }

    int extractMin();

    void decreaseKey(int vertex, int newKey);

    bool isInMinHeap(int vertex) {
        for(int i = 0; i < size; i++) {
            if (heapArray[i] == vertex) {
                return true;
            }
        }

        return false;
    }

    bool isEmpty();

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;

    void minHeapify(int idx) {
        if (inx >= 0 && )
    }
};

#endif