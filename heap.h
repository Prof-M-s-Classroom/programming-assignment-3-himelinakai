#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;

        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];
        // Initialize arrays
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
        // Do not add if graph is already full or if the vertex already exists
        if (size == capacity || isInMinHeap(vertex)) {
            return;
        }

        // Insert at the end of the heap
        heapArray[size] = vertex;
        keyArray[vertex] = key;
        position[vertex] = size;

        // Need to upheap if min heap rules are violated
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

    int extractMin() {
        if (size <= 0) {
            std::cout << "Empty MinHeap" << std::endl;
            return -1;
        }

        // Minimum is at root
        int min = heapArray[0];

        // Last vertex becomes the root
        heapArray[0] = heapArray[size - 1];
        keyArray[0] = keyArray[size - 1];

        if (size > 1) {
            position[heapArray[0]] = 0;
        }
        position[min] = -1;

        size--;

        // Need to down heap if the new root violates the rules of a min heap
        if (size > 0) {
            minHeapify(0);
        }

        return min;
    }

    void decreaseKey(int vertex, int newKey) {
        if (position[vertex] == -1 || keyArray[position[vertex]] <= newKey) {
            return;
        }

        // Update the key
        keyArray[position[vertex]] = newKey;

        // New key would result in "smaller" value, will need to upheap into correct spot
        int curr = position[vertex];
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
    }

    bool isInMinHeap(int vertex) {
        return position[vertex] != -1 && position[vertex] < size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        std::cout << "Heap Array: ";
        for (int i = 0; i < size; i++) {
            std::cout << heapArray[i] << " ";
        }
        std::cout << std::endl;


        std::cout << "Key Array: ";
        for (int i = 0; i < size; i++) {
            std::cout << keyArray[i] << " ";
        }
        std::cout << std::endl;


        std::cout << "Position Array: ";
        for (int i = 0; i < capacity; i++) {
            if (position[i] != -1)
                std::cout << i << "->" << position[i] << " ";
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
        // Stored in array so need to find index of children
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        // Find the smallest between vertex and its children
        if (left < size && keyArray[left] < keyArray[smallest])
            smallest = left;


        if (right < size && keyArray[right] < keyArray[smallest])
            smallest = right;


        // If the smallest is not the current vertex, swap and continue heapifying
        if (smallest != idx) {
            std::swap(heapArray[idx], heapArray[smallest]);
            std::swap(keyArray[idx], keyArray[smallest]);


            // Update position array
            position[heapArray[idx]] = idx;
            position[heapArray[smallest]] = smallest;


            // Recursively heapify until minimum vertex is in correct spot
            minHeapify(smallest);
        }

    }
};

#endif