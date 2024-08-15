#include <iostream>
using namespace std;

int main(){
    int n;
    int dig;
    int rev=0;
    cout<<"Enter a number-";
    cin>>n;
    int n1=n;
    while(n1>0){
        dig=n1%10;
        rev=rev*10+dig;
        n1=n1/10;}
    if(rev==n){
        cout<<"It is a Palindrome Number"<<endl;
    }
    else{
        cout<<"It is not a Palindrome Number"<<endl;
    }
}