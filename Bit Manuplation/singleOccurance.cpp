#include <iostream>
int main(){
    int nums[]={4,1,2,1,2};
    int result=0;
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
        result=result^nums[i];
    }
    std::cout<<result;
}