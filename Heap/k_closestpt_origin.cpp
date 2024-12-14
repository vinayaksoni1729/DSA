#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Function to calculate the distance from the origin
double calculateDistance(int x, int y) {
    return sqrt(x * x + y * y);
}

vector<vector<int>> kClosestPoints(vector<vector<int>>& points, int k) {
    // Max-heap to store the k closest points
    // Pair structure: {distance, point index}
    priority_queue<pair<double, int>> maxHeap;

    for (int i = 0; i < points.size(); i++) {
        // Calculate the distance of the point from the origin
        double distance = calculateDistance(points[i][0], points[i][1]);

        // Push the distance and index into the maxHeap
        maxHeap.push({distance, i});

        // If the heap size exceeds k, remove the farthest point
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    // Extract the k closest points from the heap
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }

    return result;
}
  
int main() {
    // Example points
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> result = kClosestPoints(points, k);

    cout << "The " << k << " closest points to the origin are:" << endl;
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}
