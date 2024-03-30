#include <stdio.h>
//also known as max sub-array sum
int Maxsubarray(int a[],int n){
    int maxsum=0;
    int cursum=0;
    for(int i=0;i<n;i++){
        cursum=cursum+a[i];
        if(cursum>maxsum){
            maxsum=cursum;
        }
        if(cursum<0){
            cursum=0;
        }
    }
    return maxsum;
}


int main(){
    int arr[]={5,-4,-2,6,-1};
    int n=5;
    int ans=Maxsubarray(arr,n);
    printf("mss is %d",ans);
}