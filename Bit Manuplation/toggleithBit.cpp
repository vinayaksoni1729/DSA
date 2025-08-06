#include <iostream>
int main(){
    int num=10;
    int i=2;
    std::cout<<num<<"\n";
    num=num^(1<<i);
    std::cout<<num;
}