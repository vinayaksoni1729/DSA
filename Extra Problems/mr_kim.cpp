#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<int>x,y;
int n,minDistance;

int calculateDistance(int i,int j){
    return abs(x[i]-x[j])-abs(y[i]-y[j]);
}

void findOptimalPath(int current,vector<bool>& visited,int visitedCount,int currentDistance){
    if(visitedCount==n){
        minDistance=min(minDistance,currentDistance+calculateDistance(current,n+1));
        return;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            findOptimalPath(i,visited,visitedCount+1,currentDistance+calculateDistance(current,i));
            visited[i]=false;
        }
    }
}

int main(){
    int testCases;
    cin>>testCases;

    for(int t=1;t<=testCases;t++){
        cin>>n;
        x.resize(n+2);
        y.resize(n+2);
        cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        minDistance=INT_MAX;
        vector<bool> visited(n+2,false);
        findOptimalPath(0,visited,0,0);
        cout<<"#"<<t<<" "<<minDistance<<endl;
    }
    return 0;
}