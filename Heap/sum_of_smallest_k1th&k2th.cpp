#include <iostream>
#include <queue>
using namespace std;

int findKthSmallest(int arr[],int n,int k){
    priority_queue<int> maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.push(arr[i]);

        if(maxHeap.size()>k){
            maxHeap.pop();
        } 
    }
    return maxHeap.top();
}
int sumfinder(int arr[],int n,int k1,int k2){
    int firstno=findKthSmallest(arr,n,k1);
    int secondno=findKthSmallest(arr,n,k2);
    int sum=0;
    for(int i = 0; i <n; i++){
        if(arr[i] > firstno && arr[i] < secondno){
            sum=sum+i;
        }
    }
    return sum;
}
int main(){
    int arr[]{1,3,12,5,15,11};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k1=3,k2=6;
    int result=sumfinder(arr,n,k1,k2);
    cout<<"Sum is "<<result;
}