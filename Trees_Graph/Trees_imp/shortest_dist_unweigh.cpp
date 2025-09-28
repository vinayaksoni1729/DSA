#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int> dist(n,INT_MAX);
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                if((dist[node])+1 <dist[i]){
                    dist[i]=dist[node]+1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    vector<int> ans=obj.shortestPath(adj,0);
    for(auto i:ans){
        cout<<i<<" ";
    }
}