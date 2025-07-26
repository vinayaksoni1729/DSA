#include <iostream>
#include <vector>
void printSubsets(std::vector<int>& arr,std::vector<int>& ans,int i){
    if(i==arr.size()){ //check for loop to go till bottom of recursion tree
        for(int val:ans){
            std::cout<<val<<" ";
        }
        std::cout<<std::endl;
        return;
    }
    ans.push_back(arr[i]);//including insclusion step
    printSubsets(arr,ans,i+1);//recursion for include step
    ans.pop_back();//backtracking or removing old progress from last step
    printSubsets(arr,ans,i+1);//recursion for exclude step

}
int main(){
    std::vector<int> arr={1,2,3};
    std::vector<int> ans;
    printSubsets(arr,ans,0);
}