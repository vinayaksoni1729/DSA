#include<iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start,vector<vector<int>>&adj,vector<bool>& visited){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        
        for(int i:adj[node]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
            }
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
    bfs(0,adj,visited);
    return 0;
}