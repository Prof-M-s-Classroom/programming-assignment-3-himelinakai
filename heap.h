#ifndef HEAP_H
#define HEAP_H
#include <ranges>

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;

        heapArray = new int[capacity];
        keyArray = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            keyArray[i] = INT_MAX;
        }
        position = new int[capacity];
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

        if (size == 0) {
            keyArray[0] = key;
            position[0] = size;
            heapArray[0] = vertex;
            size++;
        }
        else {
            if (!isInMinHeap(vertex)) {
                heapArray[size] = vertex;
                keyArray[size] = key;
                position[size] = size;

                int curr = size;
                while (curr > 0) {
                   int par = (curr - 1) / 2;
                   if (keyArray[position[curr]] < keyArray[position[par]]) {
                       std::swap(position[position[curr]],position[position[par]]);
                   }
                   curr = par;
                }
                size++;
            }
        }
    }

    int extractMin() {
        if (size == 0) {
            std::cout << "Empty MinHeap" << std::endl;
            return -1;
        }

        int min = heapArray[0];
        heapArray[0] = heapArray[size];
        size--;
        minHeapify(0);
        return min;
    }

    void decreaseKey(int vertex, int newKey) {
            keyArray[position[vertex]] = newKey;
    }

    bool isInMinHeap(int vertex) {
        for(int i = 0; i < size; i++) {
            if (heapArray[i] == vertex) {
                return true;
            }
        }

        return false;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            std::cout << heapArray[i] << " ";
        }

        std::cout << std::endl;
        for (int j = 0; j < capacity; j++) {
            std::cout << keyArray[j] << " ";
        }
        std::cout << std::endl;

        for (int m = 0; m < capacity; m++) {
            std::cout << position[m] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap   pos[vertex] = pos of vertex
    int capacity;
    int size;

    void minHeapify(int idx) {
        int pos = position[idx];
    }
};

#endif