#include <iostream>
using namespace std;

void TowerOfHanoi(int,char,char,char);

int main(){
    int disk;
    cout<<"Number of disks: ";
    cin>>disk;
    TowerOfHanoi(disk,'A','B','C');
    return 0;
}
void TowerOfHanoi(int num,char x,char y,char z){
    if(num==1){
        cout<<"Move top disk from Pole "<<x<<" to Pole "<<z<<endl;
    }
    else{
        TowerOfHanoi(num-1,x,z,y);
        TowerOfHanoi(1,x,z,y);
        TowerOfHanoi(num-1,y,x,z);
    }
}