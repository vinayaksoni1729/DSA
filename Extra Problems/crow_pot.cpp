#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &overFlow,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++){
        L[i]=overFlow[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=overFlow[mid+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            overFlow[k]=L[i];
            i++;
            k++;
        }
        else{
            overFlow[k]=R[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        overFlow[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        overFlow[k]=R[j];
        j++;
        k++;
    }
    

}

void mergeSort(vector<int> &overFlow,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(overFlow,left,mid);
        mergeSort(overFlow,mid+1,right);
        merge(overFlow,left,mid,right);
    }
}

int summer(int n,int k,vector<int> &overFlow){
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=overFlow[i];
    }
    return sum;
}

int main(){
    vector<int> overFlow={3,7,9};
    int n=3;
    int k=2;
    int sum=0;
    mergeSort(overFlow,0,overFlow.size()-1);
    if (k > n) {
        cout << "Error: k cannot be greater than n";
        return 0;
    }
    else{
        int result=(n-k)*overFlow[0] + summer(n,k,overFlow); 
        cout<<"Result is "<<result;
    }
}