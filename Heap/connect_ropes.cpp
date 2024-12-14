#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void cost(int arr[],int n){
    priority_queue<int ,vector<int>,greater<int>> minHeap;
    for(int i=0;i<n;i++){
        minHeap.push(arr[i]);
    }
    int cost=0;
    while(minHeap.size()>=2){
    int first=minHeap.top();
    minHeap.pop();
    int second=minHeap.top();
    minHeap.pop();
    cost=cost+(first+second);
    minHeap.push(first+second);
    }
    cout<<"Min cost to connect ropes is "<<cost;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cost(arr,n);
    return 0;
}