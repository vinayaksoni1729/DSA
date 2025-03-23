#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <tuple>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int bfs(vector<vector<int>>& matrix,int sx,int sy,vector<pair<int,int>>& rare_elements){
    int n=matrix.size();
    int m=matrix[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int>(m,-1));

    q.push({sx,sy});
    dist[sx][sy]=0;
    int max_dist=0;

    while(!q.empty()){
        int x,y;
        tie(x,y)=q.front();
        q.pop();

        for(auto& rare:rare_elements){
            if(x==rare.first && y==rare.second){
                max_dist=max(max_dist,dist[x][y]);
            }
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && matrix[nx][ny]==1 && dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    return max_dist;
}

int findBestLocation(vector<vector<int>>& matrix,vector<pair<int,int>>& rare_elements){
    int n=matrix.size();
    int m=matrix[0].size();
    int min_of_max_dist=INT_MAX;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1){
                int max_dist=bfs(matrix,i,j,rare_elements);
                if(max_dist>0){
                    min_of_max_dist=min(min_of_max_dist,max_dist);
                }
            }
        }
    }
    return (min_of_max_dist==INT_MAX)?-1:min_of_max_dist;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    vector<pair<int, int>> rare_elements = {{0, 0}, {0, 4}, {4, 0}, {4, 4}}; // Given rare element positions
    int result = findBestLocation(matrix, rare_elements);
    cout << "Shortest of the longest distance: " << result << endl;
    return 0;
}