#include <iostream>
#include <queue>
using namespace std;

void function(int arr[],int n,int k,vector<int> num){
    priority_queue<int> maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.push(arr[i]);

        if(maxHeap.size()>k){
            maxHeap.pop();
        } 
        num.push_back(maxHeap.top());
    }
}
int sumfinder(vector<int> num,int arr[],int n){
    int sum;
    int firstno=num[0];
    int secondno=num[1];
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
    vector<int> num={};
    int k1=3,k2=6;
    function(arr,n,k1,num);
    function(arr,n,k2,num);
    int result=sumfinder(num,arr,n);
    cout<<"Sum is "<<result;
}