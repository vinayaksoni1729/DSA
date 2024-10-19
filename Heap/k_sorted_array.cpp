#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void sortKSortedArray(int arr[], int size, int k) {
    // Min-heap (priority_queue by default is max-heap, so we use greater<> for min-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Add first k+1 elements to the heap
    for (int i = 0; i <= k && i < size; i++) {
        minHeap.push(arr[i]);
    }

    int index = 0;

    // Process the remaining elements, ensuring the heap always has k+1 elements
    for (int i = k + 1; i < size; i++) {
        // Place the minimum element from the heap into the array
        arr[index++] = minHeap.top();
        minHeap.pop();

        // Push the current element into the heap
        minHeap.push(arr[i]);
    }

    // Empty the remaining elements from the heap
    while (!minHeap.empty()) {
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    sortKSortedArray(arr, size, k);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
