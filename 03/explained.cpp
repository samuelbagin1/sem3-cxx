#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};



// Function to sort an array of integers using insertion sort
void insertionSort(int *data, const size_t length) {
    // Iterate through the array starting from the second element
    for (size_t i = 1; i < length; i++) {
        // Store the current element
        int tmp = data[i];
        // Initialize position for comparison
        size_t p = i;

        // Move elements greater than tmp to the right
        while (p > 0 && data[p-1] < tmp) {
            // Shift element to the right
            data[p] = data[p-1];
            // Move to the previous position
            --p;
        }

        // Insert tmp in its correct position
        data[p] = tmp;
    }
}

// Function to sort an array of strings using insertion sort
void insertionSort(const char *data[]) {
    size_t length = 0;
    // Count the number of strings in the array
    while (data[length] != nullptr) length++;

    // Iterate through the array starting from the second string
    for (size_t i = 1; i < length; i++) {
        // Store the current string
        const char* tmp = data[i];
        // Initialize position for comparison
        size_t p = i;

        // Move strings lexicographically smaller than tmp to the right
        while (p > 0 && strcmp(data[p-1], tmp) < 0) {
            // Shift string pointer to the right
            data[p] = data[p-1];
            // Move to the previous position
            --p;
        }

        // Insert tmp in its correct position
        data[p] = tmp;
    }
}

// Function to sort a linked list using insertion sort
void insertionSort(List * list) {
    // Check if the list is empty or has only one element
    if (list == nullptr || list->first == nullptr || list->first->next == nullptr) {
        return;
    }

    Node* sorted = nullptr; // Head of the sorted list
    Node* current = list->first; // Current node to be inserted

    // Iterate through the original list
    while (current != nullptr) {
        Node* next = current->next; // Store the next node

        // If sorted list is empty or current node is greater than the head
        if (sorted == nullptr || sorted->data <= current->data) {
            // Insert at the beginning of sorted list
            current->next = sorted;
            sorted = current;
        } else {
            // Find the correct position to insert
            Node* search = sorted;
            while (search->next != nullptr && search->next->data > current->data) {
                search = search->next;
            }
            // Insert the current node
            current->next = search->next;
            search->next = current;
        }

        current = next; // Move to the next node in the original list
    }

    list->first = sorted; // Update the head of the list
}

// Function to merge two sorted subarrays
void mergeNeighbours(int *output, const int *input, const size_t low, const size_t middle, const size_t high) {
    size_t in1 = low;    // Index for first subarray
    size_t in2 = middle; // Index for second subarray
    size_t out = low;    // Index for output array

    // Compare elements from both subarrays and merge
    while (in1 < middle && in2 < high) {
        if (input[in1] >= input[in2]) {
            output[out] = input[in1];
            in1++;
        } else {
            output[out] = input[in2];
            in2++;
        }
        out++;
    }

    // Copy remaining elements from first subarray, if any
    while (in1 < middle) {
        output[out] = input[in1];
        out++;
        in1++;
    }
    // Copy remaining elements from second subarray, if any
    while (in2 < high) {
        output[out] = input[in2];
        out++;
        in2++;
    }
}

// Helper function to swap two integer pointers
void swapPointers(int** a, int** b) {
    int* tmp = (*a);
    (*a) = (*b);
    (*b) = tmp;
}

// Function to sort an array using merge sort
void mergeSort(int *data, const size_t length) {
    // Create a temporary array for merging
    int* tmp = new int[length];

    int* input = data;   // Pointer to input array
    int* output = tmp;   // Pointer to output array
    bool needCopy = false; // Flag to determine if copying back to original array is needed

    // Perform merge sort
    for (size_t step = 1; step < length; step *= 2) {
        for (size_t i = 0; i < length; i += 2*step) {
            size_t low = i;
            size_t middle = std::min(i+step, length);
            size_t high = std::min(i+2*step, length);
            // Merge subarrays
            ::mergeNeighbours(output, input, low, middle, high);
        }

        // Swap input and output pointers
        needCopy = !needCopy;
        swapPointers(&input, &output);
    }

    // If final result is in tmp array, copy it back to data
    if (needCopy) {
        memcpy(data, tmp, length*sizeof(int));
    }
    // Free temporary array
    delete[] tmp;
}


int main() {
    return 0;
}
