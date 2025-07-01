
#include <iostream>
bool palindrome_check(int x){
    int x_org=x;
    int unit;
    int y=0;
    while(x>0){
        unit=x%10;
        x=x/10;
        y=y*10+unit;
    }
    if(y==x_org){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int x;
    std::cout<<"Enter number to check for palindrome-";
    std::cin>>x;
    if(palindrome_check(x)){
        std::cout<<"Valid";
    }
    else{
        std::cout<<"Invalid";
    }

}