#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>> &adj, int start, vector<int> &color) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Assign the first color (0)
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (color[neighbor] == -1) { // If not colored, assign opposite color
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false; // Found same color on both adjacent nodes, not bipartite
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges
    
    vector<vector<int>> adj(n);
    vector<int> color(n, -1); // -1 indicates unvisited
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bool bipartite = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) { // If not visited, run BFS
            if (!isBipartite(adj, i, color)) {
                bipartite = false;
                break;
            }
        }
    }
    
    if (!bipartite) {
        cout << "-1" << endl;
    } else {
        vector<int> setA, setB;
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) setA.push_back(i);
            else setB.push_back(i);
        }
        
        // Print one of the sets (choosing setA)
        for (int node : setA) cout << node << " ";
        cout << endl;
    }
    
    return 0;
}
