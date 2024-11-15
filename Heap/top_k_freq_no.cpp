#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count frequencies using a map
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Step 2: Use a min-heap to store top k frequent elements
    // Pair structure: {frequency, number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (auto& entry : freqMap) {
        minHeap.push({entry.second, entry.first});

        // If heap size exceeds k, remove the least frequent element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Step 3: Extract elements from the heap into a result vector
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second); // Push the number
        minHeap.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    cout << "The top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
