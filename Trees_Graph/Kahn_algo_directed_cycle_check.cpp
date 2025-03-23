#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> inDegree(V, 0);
        queue<int> q;

        // Step 1: Compute in-degree of each node
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }

        // Step 2: Push all nodes with in-degree 0 into the queue
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: BFS Processing
        int count = 0; // Track number of nodes processed
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // Reduce in-degree of all neighbors
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If all nodes are processed, no cycle exists
        return count != V; // If count < V, a cycle exists
    }
};

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> adj(n);
    
    // Creating the given graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[1].push_back(4);
    adj[4].push_back(1);
    
    adj[2].push_back(3);
    adj[3].push_back(2);
    
    adj[4].push_back(3);
    adj[3].push_back(4);

    Solution sol;
    if (sol.isCyclic(n, adj)) 
        cout << "Cycle detected\n";
    else 
        cout << "No cycle\n";

    return 0;
}