#include <iostream>
using namespace std;

int main(){
    int arr[]={1,5,3,2,1,3,5,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    //precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    //to check occurence(suppose if we want to check for occurence of 1,2,3,12)
    int check[]={1,2,3,12,5};
    for(int number:check){
        cout<<hash[number]<<endl;
    }
}