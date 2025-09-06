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
 void insertAtTail(int val,Node* &head){
    Node* newNode=new Node(val);
    //if its empty
    if(!head){
        head=newNode;
        return;
    }
    //traverse till we reaach end of ll
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
 }
 void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<"\n";
        head=head->next;
    }
 }
 Node* reverse(Node* &head){
    Node* prev=nullptr;
    Node* curr=head;
    Node* next=nullptr;
    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
 }
int main(){
    Node* head=nullptr;
    insertAtTail(1, head);
    insertAtTail(2, head);
    insertAtTail(3, head);
    insertAtTail(4, head);
    print(head);
    cout<<"Reversed LL\n";
    head=reverse(head);
    print(head);
    return 0;
}