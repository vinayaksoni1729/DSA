#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

void finder(int arr[][2],int n ,int k){
    priority_queue<pair<int, pair<int, int>>> maxHeap;

for(int i=0;i<n;i++){
    int distance=arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1];
    maxHeap.push({distance,{arr[i][0],arr[i][1]}});
    if(maxHeap.size()>k){
        maxHeap.pop();
    }   
}
while(!maxHeap.empty()){
    pair<int,int> points=maxHeap.top().second;
    cout<<points.first<<","<<points.second<<endl;
    maxHeap.pop();
}
}
int main(){
    int arr[][2] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    finder(arr,n,k);

    return 0;
}