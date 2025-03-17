#include <iostream>
#include <unordered_set>
using namespace std;

bool isValid(int num,const unordered_set<int>& restrictedDigits,int maxCount){
    int digitCount[10]={0};
    while(num){
        int digit=num%10;
        if(restrictedDigits.count(digit)){
            digitCount[digit]++;
            if(digitCount[digit]>=maxCount) return false;
        }
        num=num/10;
    }
    return true;
}

int countValidNumbers(int a, int b, int maxCount, const unordered_set<int>& restrictedDigits) {
    int validCount = 0;

    for (int i = a; i <= b; i++) {
        if (isValid(i, restrictedDigits, maxCount)) {
            validCount++;
        }
    }

    return validCount;  // Return the count of valid numbers
}



int main() {
    int a, b, k, n;
    cout<<"Input a,b,k,n-";
    cin >> a >> b >> k >> n;
    
    unordered_set<int> restrictedDigits;
    cout<<"Enter n digits-";
    for (int i = 0; i < n; i++) {
        int digit;
        cin >> digit;
        restrictedDigits.insert(digit);
    }
    
    cout << countValidNumbers(a, b, k, restrictedDigits) << "\n";
    
    return 0;
}