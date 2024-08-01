#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
 
void printList(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

