#include <iostream>
int main(){
    int a=10;
    int b=5;
    int diff=a^b;
    int count=0;
    for(int i=0;i<31;i++){
        if(diff & (1<<i)){
            count++;
        }
    }
    std::cout<<"Min bits need to make both numbers same is "<<count;
}
//5- 101
//10- 1010