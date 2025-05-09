#ifndef HEAP_H
#define HEAP_H

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

        if (!isInMinHeap(vertex)) {
            heapArray[size] = vertex;
            keyArray[size] = key;
            position[size] = size;
            minHeapify(size);
            size++;
        }
    }

    int extractMin() {
        if (size == 0) {
            std::cout << "Empty MinHeap" << std::endl;
            return -1;
        }

        int min = heapArray[0];
        for (int i = 0; i < size; i++) {
            heapArray[i] = heapArray[i + 1];
        }
        heapArray[size] = INT_MAX;
        size--;
        return min;
    }

    void decreaseKey(int vertex, int newKey) {

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
    }

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
        if (idx > 0 && idx <= size && size > 0) {
            for (int i = idx - 1; i >= 0; i--) {
                if (heapArray[idx] < heapArray[i]) {
                    int tempKey = keyArray[i];
                    int tempPos = position[i];
                    int temp = heapArray[i];
                    keyArray[i] = keyArray[idx];
                    position[i] = position[idx];
                    heapArray[i] = heapArray[idx];
                    keyArray[idx] = tempKey;
                    position[idx] = tempPos;
                    heapArray[idx] = temp;
                    idx--;
                }
            }
        }

        return;
    }
};

#endif