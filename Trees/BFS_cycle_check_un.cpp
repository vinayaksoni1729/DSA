#include <bits/stdc++.h>
using namespace std;

bool isCycleBFS(int start, vector<int> adj[], vector<int> &visited) {
    queue<pair<int, int>> q; // (node, parent)
    q.push({start, -1});
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) { 
                visited[neighbor] = 1;
                q.push({neighbor, node});
            }
            else if (neighbor != parent) { 
                return true; // Cycle detected
            }
        }
    }
    return false;
}

bool detectCycle(int n, vector<int> adj[]) {
    vector<int> visited(n, 0); // Mark all nodes as unvisited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // Check each component
            if (isCycleBFS(i, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    int n = 5; // Number of nodes
    vector<int> adj[n];
    
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

    if (detectCycle(n, adj)) 
        cout << "Cycle detected\n";
    else 
        cout << "No cycle\n";

    return 0;
}
