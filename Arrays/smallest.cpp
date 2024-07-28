#include <iostream>
using namespace std;

int main(){
    int a[]={5,4,3,6,2,8};
    int small=a[0];
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        if(a[i]<small){
            small=a[i];
        }
    }
    cout<<"Smallest element is: "<<small<<endl;
}