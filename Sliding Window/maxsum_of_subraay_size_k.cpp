#include <iostream>
using namespace std;

int maxSum(int k,int arr[],int n){
    if (n < k) {
        cout << "Invalid input: k is larger than the array size." << endl;
        return -1;
    }
    int maxVal=0,windowSum=0;
    for(int i=0;i<k;i++){  //initialization of first subarray 
        windowSum+=arr[i];  //whether it is max or not
    }
    maxVal=windowSum;
    for(int i=k;i<n;i++){
        windowSum+=arr[i]-arr[i-k];
        maxVal=max(windowSum,maxVal);
    }
    return maxVal;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    int result=maxSum(k,arr,n);
    cout<<"Sum of max SubArray is-"<<result;
    return 0;
}