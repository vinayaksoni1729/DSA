#include <stdio.h>

int main(){
    int n=5;
    int arr[]={1,4,2,9,5,3};
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp;
            arr[temp]=arr[min];
            arr[min]=arr[i];
            arr[i]=arr[temp];
        }
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}