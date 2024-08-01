#include <iostream>
using namespace std;

int main(){
    string s=")()())))";
    int n=s.length();
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        if(s[i]==')'){
            if(s[i-1]=='('){
                dp[i]=(i>=2?dp[i-2]:0)+2;
            }
            else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                dp[i]=dp[i-1]+((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0)+2;
            }
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
    return 0;
}