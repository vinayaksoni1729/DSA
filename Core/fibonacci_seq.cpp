#include <iostream>
void fib_fun(int n){
    int current=1;
    int summer=0;
    int fib;
    while(summer<=n){
        std::cout<<summer<<"\n";
        fib=summer+current;
        summer=current;
        current=fib;
    }
}

int main(){
    int n;
    std::cout<<"Enter limit for series-";
    std::cin>>n;
    fib_fun(n);
}