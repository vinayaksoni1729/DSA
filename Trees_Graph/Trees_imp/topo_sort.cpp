#include<iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topoSort(int V,vector<vector<int>>& adj){
  vector<int> inDegree(V,0);
  queue<int> q;
  //make indegree 
  for(int i=0;i<V;i++){
    for(int neighbor:adj[i]){
      inDegree[neighbor]++;
    }
  }
  //push all nodes with indegree 0
  for(int i=0;i<V;i++){
    if(inDegree[i]==0){
      q.push(i);
    }
  }
  //bfs treversal
  vector<int> topo;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    topo.push_back(node);
    for(int neighbor:adj[node]){
      inDegree[neighbor]--;
      if(inDegree[neighbor]==0){
        q.push(neighbor);
      }
    }
  }
  return topo;
}
int main() {
    int n = 6; // Number of nodes
    vector<vector<int>> adj(n);
    
    // Creating the given graph
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    vector<int> ans=topoSort(n,adj);
    for(int i:ans){
      cout<<i<<" ";
    }

    return 0;
}