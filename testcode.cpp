#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> &adj, int start, vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbour : adj[node])
        {
            if (color[neighbour] == -1)
            {
                color[neighbour] = 1 - color[node];
                q.push(neighbour);
            }
            else if (color[neighbour] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> color(n, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> n >> m;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool bipartite = true;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(adj, i, color))
            {
                bipartite = false;
                break;
            }
        }
    }
    if (!bipartite)
    {
        cout << "-1" << endl;
    }
    else
    {
        vector<int> setA, setB;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
                setA.push_back(i);
            else
                setB.push_back(i);
        }
        for (int node : setA)
            cout << node << " ";
        cout << endl;
    }
    return 0;
}