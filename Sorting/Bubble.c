#include <stdio.h>

void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
for(int k=0;k<n;k++){
    printf("%d\n",arr[k]);
    }
}

int main(){
    int arr[]={-2,6,62,-4,-1,0,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
}
