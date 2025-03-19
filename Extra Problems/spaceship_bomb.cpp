#include <bits/stdc++.h>
using namespace std;


void updateMatrix(int row,vector<vector<char>>& matrix){
    if(row<0) return ;
    int upLimit=max(0,row-4);
    for(int i=row;i>=upLimit;i--){
        for(int j=0;j<5;j++){
            if(matrix[i][j]=='2'){
                matrix[i][j]='0';
            }
        }
    }
}

int findMaxPoints(int row,int col,int bombs,vector<vector<char>>& matrix){
    queue<tuple<int,int,int,int,vector<vector<char>>>> q;
    q.push({row,col,bombs,0,matrix});
    int max_coins=0;

    while(!q.empty()){
        int r,c,b,coins;
        vector<vector<char>> curr_matrix;
        tie(r,c,b,coins,curr_matrix)=q.front();
        q.pop();

        if(r<=0){
            max_coins=max(max_coins,coins);
            continue;
        }
        if(curr_matrix[r-1][0]!='2'){
            q.push({r-1,c,b,coins+(curr_matrix[r-1][c]=='1'?1:0),curr_matrix});
        }
        if(c>0 && curr_matrix[r-1][c-1]!='2'){
            q.push({r-1,c-1,b,coins+(curr_matrix[r-1][c-1]=='1'?1:0),curr_matrix});
        }
        if(c<4 && curr_matrix[r-1][c+1]!='2'){
            q.push({r-1,c+1,b,coins+(curr_matrix[r-1][c+1]=='1'?:0),curr_matrix});
        }
        if(b>0){
            vector<vector<char>> new_matrix=curr_matrix;
            updateMatrix(r-1,new_matrix);
            q.push({r,c,b-1,coins,new_matrix});
        }
    }
    return max_coins;
}

int main(){
    int t,row;
    cin>>t;
    int tNo=0;
    while(t--){
        cin>>row;
        vector<vector<char>> matrix(row,vector<char>(5));
        for(int i=0;i<row;i++){
            for(int j=0;j<5;j++){
                cin>>matrix[i][j];
            }
        }
        tNo++;
        cout << "#" << tNo << " : " << findMaxPoints(row, 2, 1, matrix) << endl;        
    }
    return 0;
}