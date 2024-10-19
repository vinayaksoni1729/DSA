#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void sortKSortedArray(int arr[],int size,int k){
    priority_queue<int, vector<int>,greater<int>> minHeap;

    for(int i=0;i<=k && i<size;i++){
        minHeap.push(arr[i]);
    }
    int index=0;

    for(int i=k+1;i<size;i++){
        arr[index++]=minHeap.top();
        minHeap.pop();

        minHeap.push(arr[i]);
    }
    while(!minHeap.empty()){
        arr[index++]=minHeap.top();
        minHeap.pop();
    }
}
int main(){
    int arr[]={6,5,3,2,8,10,9};
    int k=3;
    int size=sizeof(arr)/sizeof(arr[0]);
    sortKSortedArray(arr,size,k);

    cout<<"Sorted array:";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
