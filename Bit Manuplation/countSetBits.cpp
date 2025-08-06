#include <iostream>
int countSetBits(int n){
    int count=0;
    while(n>=1){
        count+=n&1;
        n=n>>1;
    }
    return count;
}

int main(){
    int num=4;
    std::cout<<countSetBits(num);

}