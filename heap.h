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
        position = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            keyArray[i] = INT_MAX;
            heapArray[i] = INT_MAX;
            position[i] = -1;
        }
    }

    ~MinHeap() {
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }

    void insert(int vertex, int key) {
        if (!isInMinHeap(vertex) && size < capacity) {
            heapArray[size] = vertex;
            position[vertex] = size;
            keyArray[size] = key;

            int curr = size;
            int parent = (curr - 1) / 2;
            while (curr > 0 && keyArray[curr] < keyArray[parent]) {
                // Swap the nodes
                std::swap(heapArray[curr], heapArray[parent]);
                std::swap(keyArray[curr], keyArray[parent]);


                // Update position array
                position[heapArray[curr]] = curr;
                position[heapArray[parent]] = parent;


                // Move up
                curr = parent;
                parent = (curr - 1) / 2;
            }

            size++;
        }
    }

    int extractMin() {
        if (size == 0) {
            std::cout << "Empty MinHeap" << std::endl;
            return -1;
        }

        int min;
        if (size == 1) {
            min = heapArray[0];
            position[0] = -1;
            heapArray[0] = INT_MAX;
            size--;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (position[i] == 0) {
                    min = heapArray[i];
                    position[i] = -1;
                    heapArray[i] = INT_MAX;
                }
            }

            int maxIdx = 0;
            for (int j = 1; j < size; j++) {
                if (position[maxIdx] < position[j]) {
                    maxIdx = j;
                }
            }

            position[maxIdx] = 0;
            size--;
            minHeapify(maxIdx);
        }

        return min;
    }

    void decreaseKey(int vertex, int newKey) {
        if (position[vertex] == -1 || keyArray[position[vertex]] <= newKey) {
            keyArray[position[vertex]] = newKey;
        }
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
            std::cout << heapArray[i] << " " << std::endl;
        }
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap   pos[vertex] = pos of vertex
    int capacity;
    int size;

    void minHeapify(int idx) {
        int left = 0, right = 0;
        int curr = position[idx];
        std::cout << curr << std::endl;

        while (curr < size) {

            left = 2 * curr + 1;
            right = 2 * curr + 2;
            std::cout << left << " " << right << std::endl;

            //If both left and right exist
            if(left <= size && right <= size) {
                if (keyArray[position[curr]] <= keyArray[position[left]] && keyArray[position[curr]] <= keyArray[right]) {
                    std::cout << keyArray[position[curr]] << " " << std::endl;
                    std::cout << "Node is less that left & right child"<<std::endl;
                    return;
                }
                if (keyArray[position[right] - 1] <= keyArray[position[left] - 1]) { //curr is greater than right child
                    std::swap(position[position[curr]], position[position[right]]);
                    curr = right;
                } else { //curr is greater than left child
                    std::swap(position[position[curr]], position[position[left]]);
                    curr = left;
                }
            }
            //only left exists
            if(right > size){
                if (keyArray[position[left]] < keyArray[position[curr]]) { //curr is greater than left child
                    std::swap(position[position[curr]], position[position[left]]);
                    curr = left;
                }
                else return;
            }
        }
    }
};

#endif