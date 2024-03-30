#include <stdio.h>

int main(){
    int n=5;
    int arr[]={1,4,2,9,5,3};
    for(int i=1;i<n;i++){
        int current=arr[i];
        int j=i-1;
        while(arr[j]>current && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}