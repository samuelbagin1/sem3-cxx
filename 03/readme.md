### ```insertionSort(int *data, const size_t length)```:
This function implements the insertion sort algorithm for an array of integers. It sorts the array in descending order (from largest to smallest).

- It iterates through the array starting from the second element.
- For each element, it compares it with the previous elements and shifts larger elements to the right.
- It then inserts the current element in its correct position.


### ```insertionSort(const char *data[])```:
This function implements insertion sort for an array of strings (char pointers). It sorts the strings in descending lexicographic order.

- It first counts the number of strings in the array (until it encounters a nullptr).
- It then uses a similar approach to the integer insertion sort, but compares strings using strcmp().
- It rearranges the pointers to the strings rather than the strings themselves.


### ```insertionSort(List * list)```:
This function performs insertion sort on a linked list, sorting the nodes in descending order.

- It creates a new sorted list and iterates through the original list.
- For each node, it finds the correct position in the sorted list and inserts it there.
- It handles cases where the node should be inserted at the beginning or somewhere in the middle of the sorted list.
- Finally, it updates the head of the original list to point to the sorted list.


### ```mergeNeighbours(int *output, const int *input, const size_t low, const size_t middle, const size_t high)```:
This function merges two sorted subarrays of the input array into a single sorted subarray in the output array. It's part of the merge sort algorithm.

- It compares elements from both subarrays and places them in the correct order in the output array.
- It handles cases where one subarray is exhausted before the other.


### ```swapPointers(int** a, int** b)```:
A helper function that swaps two integer pointers.

### ```mergeSort(int *data, const size_t length)```:
This function implements the merge sort algorithm to sort an array of integers in descending order.

- It creates a temporary array to assist with merging.
- It uses a bottom-up approach, starting with subarrays of size 1 and doubling the size in each iteration.
- It alternates between using the input array and the temporary array as source and destination for merging.
- It uses the mergeNeighbours function to perform the merging step.
- If the final sorted result is in the temporary array, it copies it back to the original array.