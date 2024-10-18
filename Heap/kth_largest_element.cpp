#include <iostream>
#include <queue> // Include for priority_queue
using namespace std;

int main() {
    int arr[] = {7, 10, 9, 3, 20, 15};
    int k = 4;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Max-heap to store the smallest k elements
    priority_queue<int, vector<int>, greater<int>> minheap;

    // Push elements to the heap
    for (int i = 0; i < size; i++) {
        minheap.push(arr[i]);

        // If heap size exceeds k, remove the largest element
        if (minheap.size() > k) {
            minheap.pop();
        }
    }

    // The top of the heap will be the k-th smallest element
    cout << "The " << k << "-th smallest element is: " << minheap.top() << endl;

    return 0;
}
