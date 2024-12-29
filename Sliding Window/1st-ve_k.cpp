#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void firstNegativeNumber(int arr[], int n, int k) {
    deque<int> dq; // To store indices of negative numbers
    vector<int> result; // To store the first negative number in each window

    // Process the first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i); // Store index of negative number
        }
    }

    // Process the rest of the windows
    for (int i = k; i < n; i++) {
        //Here i will be end element of our window
        // Record the first negative number for the current window
        if (!dq.empty()) {
            result.push_back(arr[dq.front()]);
        } else {
            result.push_back(0); // No negative number in this window
        }

        // Remove indices that are no longer part of the window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Add the current element if it is negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // Process the last window
    if (!dq.empty()) {
        result.push_back(arr[dq.front()]);
    } else {
        result.push_back(0);
    }

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
}

int main() {
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "First negative number in each window of size " << k << ": ";
    firstNegativeNumber(arr, n, k);
    return 0;
}
