#include <iostream>
#include <queue>
using namespace std;

struct Pipe{
    bool up,own ,left,maxLen;
};
const int MAX=1005;
int n,m,startX,startY,maxLen;
bool visited[MAX][MAX];
Pipe pipes[MAX][MAX];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int bfs(){
    if(grid[startX][startY]==0) return 0;
    queue<pair<int,int>> q;
    q.push({startX,startY});
    visited[startX][startY]=true;
    int explored=1,level=1;
        while(!q.empty(){
            int size=q.size();
            while(size--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny``     =y+dy[i];


                }
            }
        })

}
bool isValid(int x,int y){
    return (x>=0 && x<n && y>=0 && y<m);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>startX>>startY>>maxLen;
        for(int i=0;i<n;i++){
            cin>>grid[i][j];
            visited[i][j]=false;
        }
        cout<<bfs()<<endl;
    }
}