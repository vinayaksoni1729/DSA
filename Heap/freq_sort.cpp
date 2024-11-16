#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> Freqsort(vector<int>& nums, int k) {
    // Step 1: Count frequencies using a map
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Step 2: Use a min-heap to store top k frequent elements
    // Pair structure: {frequency, number}
    priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;

    for (auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first});
    }

    // Step 3: Extract elements from the heap into a result vector
    vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().second); // Push the number
        maxHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4};
    int k = 2;

    vector<int> result = Freqsort(nums, k);

    cout << "The top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
