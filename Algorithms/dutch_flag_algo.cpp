#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        void sortColors(vector<int>& nums){
            int start=0,mid=0;
            int end=nums.size()-1;
            while(mid<=end){
                switch(nums[mid]){
                    case 0:
                        swap(nums[start],nums[mid]);
                        start++,mid++;
                        break;
                    case 1:
                        mid++;
                        break;
                    case 2:
                        swap(nums[mid],nums[end]);
                        end--;
                        break;
                }
            }

        }
};

int main(){
    int n;
    cout<<"size of input-";
    cin>>n;
    cout<<"Now enter elements of input-";
    int number;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>number;
        nums[i]=number;
    }
    Solution obj1;
    obj1.sortColors(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    
}