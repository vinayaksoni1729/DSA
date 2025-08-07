#include <iostream>
int main(){
    int a=10;
    int b=5;
    int diff=a^b;
    int count=0;
    while(diff){
        diff&=diff-1;
        count++;
    }
    std::cout<<"Min bits need to make both numbers same is "<<count;
}
//5- 101
//10- 1010