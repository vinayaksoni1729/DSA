#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int calculateDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int findOptimalPath(int current, vector<bool>& visited, int visitedCount, int currentDistance, 
                    vector<pair<int, int>>& points, int n, int destinationIndex, int& minDistance) {
    if (visitedCount == n) {
        minDistance = min(minDistance, currentDistance + calculateDistance(points[current].first, points[current].second, 
                                                                           points[destinationIndex].first, points[destinationIndex].second));
        return minDistance;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            findOptimalPath(i, visited, visitedCount + 1, currentDistance + 
                            calculateDistance(points[current].first, points[current].second, points[i].first, points[i].second), 
                            points, n, destinationIndex, minDistance);
            visited[i] = false;
        }
    }
    return minDistance;
}

int main() {
    int t, testCaseNo = 0;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> points(n + 2);
        cin >> points[n + 1].first >> points[n + 1].second; // Destination
        cin >> points[0].first >> points[0].second;         // Source
        
        for (int i = 1; i <= n; i++) {
            cin >> points[i].first >> points[i].second; // Drop-off locations
        }

        vector<bool> visited(n + 2, false);
        int minDistance = INT_MAX;
        
        findOptimalPath(0, visited, 0, 0, points, n, n + 1, minDistance);
        
        testCaseNo++;
        cout << "#" << testCaseNo << " : " << minDistance << endl;
    }

    return 0;
}
