#include <iostream>
#include <cstring>
#include <map>
using namespace std;

void mergeAlpha(char *str){
    map<char,int> maps;
    int n=strlen(str);
    for(int i=0;i<n;i++){
        char alpha=str[i];

        int num=0;
        while(i+1<n && isdigit(str[i+1])){
            num=num*10 + (str[i+1]-'0');
            i++;
        }
        maps[alpha]+=num;
    }
    for(auto it : maps){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    char s[100];
    cin>>s;
    mergeAlpha(s);
    return 0;
}