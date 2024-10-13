#include <iostream>
#include <queue> // Include for priority_queue
using namespace std;

int main() {
    int arr[] = {7, 10, 9, 3, 20, 15};
    int k = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Max-heap to store the smallest k elements
    priority_queue<int> maxheap;

    // Push elements to the heap
    for (int i = 0; i < size; i++) {
        maxheap.push(arr[i]);

        // If heap size exceeds k, remove the largest element
        if (maxheap.size() > k) {
            maxheap.pop();
        }
    }

    // The top of the heap will be the k-th smallest element
    cout << "The " << k << "-th smallest element is: " << maxheap.top() << endl;

    return 0;
}
