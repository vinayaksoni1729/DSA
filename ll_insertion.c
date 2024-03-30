#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
    };
    
void linkedll(struct Node *ptr){
    while(ptr != NULL)
    {
        printf("Enement: %d\n",ptr->data);
        ptr=ptr->next;
    }}
//case 1
    struct Node * insertAtfirst(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//case 3
    struct Node * insertAtEnd(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p=head;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
//case 4
    struct Node * insertAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    
    return head;
}
//case 2
    struct Node * insertAtindex(struct Node *head,int data,int index){
        struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
        struct Node * p=head;
        int i=0;
        while(i!=index-1){
            p=p->next;
            i++;
        }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
        return head;
}





int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=11;
    second->next=third;

    third->data=41;
    third->next=fourth;

    fourth->data=66;
    fourth->next=NULL;

    
    printf("Linked list before insertion");
    linkedll(head);
 //   head=insertAtfirst(head,56);
 //   head=insertAtindex(head,56,1);
    printf("\nLinked list after insertion");
 //   head=insertAtEnd(head,56);
    head=insertAfterNode(head,second,45);
    linkedll(head);
    
    return 0;
    }