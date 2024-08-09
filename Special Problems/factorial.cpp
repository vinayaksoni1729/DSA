#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter number to find factorial-";
    cin>>n;
    if(n<0){
        cout<<"Error: factorial is undefined";
    }
    else{
        cout<<"Factorial of "<<n<<" is "<<factorial(n)<<endl;
    }
}