#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){
        head=tail=nullptr;
    }
};
int main(){

    return 0;
}