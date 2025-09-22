#include<iostream>
#include <vector>
using namespace std;

void dfs(int node,vector<vector<int>>& adj,vector<bool>& visited){
    visited[node]=true;
    cout<<node<<" ";
    for(int i:adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited);
        }
    }
}
int main(){
    int n=5;
    vector<bool> visited(5,false);
    vector<vector<int>> adj(n);
    vector<pair<int,int>> edges={{0,1},{0,2},{1,2},{1,3},{2,4},{3,4}};
    for(auto &e:edges){
    int u=e.first,v=e.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    dfs(0,adj,visited);
    return 0;
}