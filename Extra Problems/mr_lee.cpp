#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<vector<int>> cost;
vector<bool> visited;
int minCost=INT_MAX;

void findMinCost(int current,int visitedCount,int totalCost){
    if(visitedCount==n){
        if(cost[current][0]!=0){
            minCost=min(minCost,totalCost+cost[current][0]);
        }
        return;
    }
    for(int next=1;next<n;next++){
        if(!visited[next] && cost[current][next]!=0){
            visited[next]=true;
            findMinCost(next,visitedCount+1,totalCost+cost[current][next]);
            visited[next]=false;
        }
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        cost.assign(n,vector<int>(n));
        visited.assign(n,false);
        minCost=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>cost[i][j];
            }
        }
        visited[0]=true;
        findMinCost(0,1,0);
        cout<<minCost<<endl;
    }
    return 0;
}