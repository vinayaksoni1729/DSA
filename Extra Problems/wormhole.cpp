#include <iostream>
#include <climits>
using namespace std;

int minDistance,numWormholes;
int wormholes[35][5];
bool usedWormhole[35];

int manhattenDistance(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int findShortestDistance(int currentX,int currentY,int destX,int destY,int currentCost){
    minDistance=min(minDistance,manhattenDistance(currentX,currentY,destX,destY)+currentCost);
    for(int i=0;i<numWormholes;i++){
        if(!usedWormhole[i]){
            usedWormhole[i]=true;
            findShortestDistance(wormholes[i][2],wormholes[i][3],destX,destY,currentCost+manhattenDistance(currentX,currentY,wormholes[i][0],wormholes[i][1])+wormholes[i][4]);
            findShortestDistance(wormholes[i][0],wormholes[i][1],destX,destY,currentCost+manhattenDistance(currentX,currentY,wormholes[i][2],wormholes[i][3])+wormholes[i][4]);
            usedWormhole[i]=false;
        }
    }
}

int main(){
    int t,startX,startY,destX,destY;
    cin>>t;
    while(t--){
        minDistance=INT_MAX;
        cin>>numWormholes>>startX>>startY>>destX>>destY;
        for(int i=0;i<numWormholes;i++){
            cin>>wormholes[i][0]>>wormholes[i][1]>>wormholes[i][2]>>wormholes[i][3]>>wormholes[i][4];
            usedWormhole[i]=false;
        }
        findShortestDistance(startX,startY,destX,destY,0);
        cout<<minDistance<<endl;
    }
}