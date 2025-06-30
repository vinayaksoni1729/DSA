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
/*
**1st approach(own)**
we keep unordered map/vector to keep count of occurance of numbers
then we will use another for loop with while to make a corresponding sorted array and replace the older one 
**2nd approach(dutch national flag algo)**
imagine 3 pointers start , mid , end 
initially start and mid at 0th index
end at n-1th index
and run while mid<=end 
case 1
if there is 0 means we need it in left side , so make it= to start also increment start and mid
case 2
if 1 means we r not sure what to do so just move mid pointer to next index
case 3 
if its 2 means we need it at end of index so make it = to end and decrement end
here we keep in mind that we r partiually sorting array and keep sorted aside and focus on unsorted part


*/