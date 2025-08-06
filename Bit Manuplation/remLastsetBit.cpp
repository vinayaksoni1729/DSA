#include <iostream>
int main(){
    int num=10;
    int i=2;
    std::cout<<num<<"\n";
    num=num&num-1;
    std::cout<<num;
}