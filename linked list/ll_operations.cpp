#include <iostream>
#include <stdlib.h>
class Node{
public:
    int data;
    Node* next;
    //initialize constructor
    Node(int val){
        data=val;
        next=nullptr;
    }
};
void insertAtTail(Node* &head,int val){
    //make a new node named "newNode"
    Node* newNode = new Node(val);
    //check if any other node is present
    if(!head){
        //if not present head is new newNode
        head=newNode;
        return;
    }
    //make a new temp node with head
    Node* temp=head;
    //while we r not on the end run loop
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    //appends newnode in the end
    temp->next=newNode;
}
void insertAtHead(Node* &head,int val){
    Node* newNode = new Node(val);
    //point new node's next to head
    newNode->next=head;
    //make newNode new head
    head=newNode;
}

void insertAtHeadRecursive(Node* &head,int val){
    Node* newNode=new Node(val);
    newNode->next=head;
    head=newNode;
}
void insertAtTailRecursive(Node* &head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    if (head->next == nullptr) {
        head->next = new Node(val);
        return;
    }
    insertAtTailRecursive(head->next, val);
}

void deleteNode(Node* &head,int val){
    //base case:if list is empty
    if(!head) return;
    //case when we need delete head
    if(head->data==val){
        Node* toDelete=head;
        //making next node head
        head=head->next;
        //deleting toDelete node
        delete toDelete;
        return;
    }
    //search for node
    Node* temp=head;
    while(temp->next!=nullptr && temp->next->data!=val){
        temp=temp->next;
    }
    //case when element is not found
    if(temp->next==nullptr){
        std::cout<<"Value "<<val<<" not found in list.\n";
        return;
    }
    //delete if found
    Node* toDelete=temp->next;
    //filling gap of toDelete node
    temp->next=temp->next->next;
    delete toDelete;

}
bool search(Node* head,int val){
    //check till end or not null position
    while(head!=nullptr){
        //check if head's data= required value
        if(head->data==val){
            return true;
        }
        //move head to next
        head=head->next;
    }
    return false;
}
Node* reverseList(Node* head){
    //used simple 3 variable swapping approach
    //making seperate pointers for prev and curr
    Node* prev=nullptr;
    Node* curr=head;
    //while we are not at end 
    while(curr!=nullptr){
        //make a new node pointer for current's next
        Node* next=curr->next;
        //set curr's next to prev
        curr->next=prev;
        //set prev to curr
        prev=curr;
        //set curr to next(prev)
        curr=next;
    }
    return prev;
}
int length(Node* head){
    int count=0;
    while(head!=nullptr){
        count++;
        head=head->next;
    }
    return count;
}
Node* findMiddle(Node* head){
    //base case when head is null(empty)
    if(head==nullptr) return nullptr;
    //make slow(1step) and fast(2step) pointer
    Node* slow=head;
    Node* fast=head;
    //while value of fast is not null and fast's next is not null
    while(fast!=nullptr && fast->next!=nullptr){
        //move slow 1 step ahead
        slow=slow->next;
        //mode fast 1 step ahead
        fast=fast->next->next;
    }
    return slow;
}
void printList(Node* head){
    //while we r not on nullptr print it's value
    while(head!=nullptr){
        std::cout<<head->data<<" ";
        head=head->next;
    }
    std::cout<<"NULL\n";
}
int main(){
    //make a head pointer node with null value
    Node* head=nullptr;
    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTailRecursive(head, 30);
    insertAtHeadRecursive(head, 5);

    printList(head);
    deleteNode(head, 2);
    printList(head);
    if(search(head, 4)){
        std::cout<<"True"<<"\n";
    }
    else{
    std::cout<<"False"<<"\n";
    }
    head=reverseList(head);
    printList(head);
    int count=length(head);
    std::cout<<"Length of LL is- "<<count<<"\n";
    Node* mid=findMiddle(head);
    if(mid) std::cout<<"Middle element is- "<<mid->data<<"\n";

}