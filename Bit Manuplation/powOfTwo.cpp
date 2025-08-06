#include <iostream>
int main(){
    int num=12;
    if((num & (num - 1)) == 0){
        std::cout<<"yes its pow of 2";
    }
    else{
        std::cout<<"No, its not pow of 2";
    }
}