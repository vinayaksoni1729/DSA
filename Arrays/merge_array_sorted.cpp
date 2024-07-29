#include <iostream>
using namespace std;

int main(){
    int arr1[]={1,3,5};
    int arr2[]={2,4,6};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int combined[n1+n2];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            combined[k++]=arr1[i++];
        }else{
            combined[k++]=arr2[j++];
        }
    }
    while(i<n1){
        combined[k++]=arr1[i++];
    }
    while(j<n2){
        combined[k++]=arr2[j++];
    }
    for(int i=0;i<n1+n2;i++){
        cout<<combined[i]<<" ";
    }
    cout<<endl;
}