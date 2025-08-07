#include <iostream>
int countSetBits(int n){
//Brian Kernighan’s algorithm:
    int count=0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}

int main(){
    int num=4;
    std::cout<<countSetBits(num);

}