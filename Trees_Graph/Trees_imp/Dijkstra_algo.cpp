#include <climits>
#include<iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src}); // {dist, node}

        while (!pq.empty()) {
            auto [d, node] = pq.top(); pq.pop();
            if (d > dist[node]) continue; // skip outdated entry

            for (auto [nei, wt] : adj[node]) {
                if (dist[node] + wt < dist[nei]) {
                    dist[nei] = dist[node] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        return dist;
    }
};

int main(){
    int n=5;
    vector<vector<pair<int,int>>> adj={{ {1,2}, {2,4} },{ {0,2}, {2,1}, {3,7} },{ {0,4}, {1,1}, {4,3} },{ {1,7} },{ {2,3} }};
    int src=0;
    Solution obj;
    vector<int> ans=obj.dijkstra(n,adj, src);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}