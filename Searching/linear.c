#include <stdio.h>

int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    int key;
    printf("Enter element to be searched-");
    scanf("%d",&key);

    int index=linearSearch(arr,n,key);
    
    if(index!=-1){
        printf("Element %d found at %d index",key,index);
    }
    else{
        printf("Element not found!");
    }

}