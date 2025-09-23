#include<iostream>
#include <vector>
using namespace std;
bool dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>& visited){
  visited[node]=true;
  for(int i:adj[node]){
    if(!visited[i]){
      if(dfs(i,node,adj,visited)) return true;
    }
    else if(i!=parent){
      return true;//cyccle found
    }
  }
  return false;
}
bool hasCycle(int n,vector<vector<int>>& edges){
  vector<vector<int>> adj(n);
  for(auto &e:edges){
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }
  vector<bool> visited(n,false);
  for(int i=0;i<n;i++){
    if(!visited[i]){
      if(dfs(i,-1,adj,visited)) return true;
    }
  }
  return false;
}
int main(){
    int n=6;
    vector<vector<int>> edges={{1,2},{2,3},{3,4},{4,5}};
    cout<<hasCycle(n,edges);
    return 0;
}