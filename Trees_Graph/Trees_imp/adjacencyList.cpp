#include<iostream>
#include <vector>
using namespace std;

int main(){
  int n=5,m=6;
  vector<vector<int>> adj(n);
  vector<pair<int,int>> edges={{0,1},{0,2},{1,2},{1,3},{2,4},{3,4}};
  for(auto &e:edges){
    int u=e.first,v=e.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  //print adjacency list
  for(int i=0;i<n;i++){
    cout<<i<<" : ";
    for(int v:adj[i]){
      cout<<v<<" ";
    }
    cout<<"\n";
  }
  return 0;
}