#include <stdio.h>
int bsearch(int arr[],int size,int target){
    int left=0;
    int right=size-1;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=3;
    int result=bsearch(arr,size,target);
    if(result!=-1){
        printf("Element fount at %d\n",result);
    }
    else{
        printf("element not found");
    }
    return 0;
}