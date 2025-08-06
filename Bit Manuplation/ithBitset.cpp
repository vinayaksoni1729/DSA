#include <iostream>
int main(){
    int num=1;
    int i=1;
    if(num & (1<<i)){
        std::cout<<"It is set";
    }
    else{
        std::cout<<"It is not set";
    }
}