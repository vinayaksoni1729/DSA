#include <iostream>
#include <string>
#include <vector>

void helper(std::vector<std::vector<int>>& mat,int r,int c,std::string path,std::vector<std::string>& ans){
    int n=mat.size();
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || mat[r][c]==-1){
        return;
    }
    if(r==n-1 && c==n-1){
        ans.push_back(path);
        return;
    }
    mat[r][c]=-1;
    helper(mat,r+1,c,path+"D",ans);//moving down
    helper(mat,r-1,c,path+"U",ans);//moving up
    helper(mat,r,c-1,path+"L",ans);//moving left
    helper(mat,r,c+1,path+"R",ans);//moving right
    mat[r][c]=1;

}
std::vector<std::string> findPath(std::vector<std::vector<int>>& mat){
    std::vector<std::string> ans;
    std::string path="";
    helper(mat,0,0,path,ans);
    return ans;
}

int main(){
    std::vector<std::vector<int>> mat ={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    std::vector<std::string> ans=findPath(mat);
    for(std::string path:ans){
        std::cout<<path<<std::endl;
    } 
}