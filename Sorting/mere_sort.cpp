#include <iostream>
#include <vector>
using namespace std;


void merge(vector<double>& arr, int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<double> L(n1), R(n2);
    
    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<double>& arr,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    vector<double> unsortedArr={3,7,6,-10,15,23.5,55,-13};
    mergeSort(unsortedArr,0,unsortedArr.size()-1);
    cout<<"Sorted array: ";{
        for(double num:unsortedArr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;

}