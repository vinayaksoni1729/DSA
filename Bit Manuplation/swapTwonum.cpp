#include <iostream>
int main(){
    int a=15;
    int b=20;
    std::cout<<"A before swapping "<<a<<"| B before swapping "<<b<<"\n";
    a=a^b;
    b=a^b;
    a=a^b;
    std::cout<<"A after swapping "<<a<<"| B after swapping "<<b<<"\n";
}