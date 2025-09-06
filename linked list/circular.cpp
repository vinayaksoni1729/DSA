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
    void insertAtHead(int val,Node* &head){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            tail->next=newNode;
            head=newNode;
        }
    }
    void insertAtTail(int val,Node* &head){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->next=head;
            tail=newNode;
        }
    }
    void print(){
        if(head==nullptr) return;
        cout<<head->data<<"->";
        Node* temp=head->next;
        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data;
    }
    void deleteAtHead(){
        if(head==nullptr) return;
        else if(head==tail){
            delete head;
            head=tail=nullptr;
        }
        else{
            Node* delNode=head;
            head=delNode->next;
            tail->next=head;
            delete delNode;
        }
    }
};
int main(){
    CircularList cll;
    Node* head=nullptr;
    cll.insertAtHead(1,head);
    cll.insertAtHead(2,head);
    cll.insertAtHead(3,head);
    cll.insertAtTail(0,head);
    cll.print();
    cout<<"\nAfter deleting\n";
    cll.deleteAtHead();
    cll.print();
    return 0;
}