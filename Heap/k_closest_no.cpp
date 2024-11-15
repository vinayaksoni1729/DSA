#include <iostream>
#include <queue>
#include <vector>
#include <cmath> // For abs()
using namespace std;

int main() {
    int arr[] = {7, 10, 9, 3, 20, 15};
    int k = 4;
    int target = 7;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Max-heap to store the closest k elements
    // Pair structure: {difference, actual number}
    priority_queue<pair<int, int>> maxheap;

    // Push elements to the heap
    for (int i = 0; i < size; i++) {
        int diff = abs(arr[i] - target);
        maxheap.push({diff, arr[i]});

        // If heap size exceeds k, remove the farthest element
        if (maxheap.size() > k) {
            maxheap.pop();
        }
    }

    // Extract and display k closest elements
    cout << "The " << k << " closest numbers to " << target << " are:" << endl;
    while (!maxheap.empty()) {
        cout << maxheap.top().second << " ";//.second is used to access actual number from the pair
        maxheap.pop();
    }
    cout << endl;

    return 0;
}
