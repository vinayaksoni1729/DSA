#include <iostream>
using namespace std;

int main(){
    string s="abcdabehf";
    //precompute
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']+=1;
    }
    //suppose we want to check occurence of abcdeyz
    string check="abcdeyz";
    for(char c:check){
        cout<<hash[c-'a']<<endl;//for c-'a' we are subtracting char from char so result will
        //be  difference of their ASCII value, which is index for our hashmap
    }
}