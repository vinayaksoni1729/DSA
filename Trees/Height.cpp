#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
int findHeight(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftheight=findHeight(root->left);
    int rightheight=findHeight(root->right);

    return max(leftheight,rightheight)+1;
}
int main(){
    cout<<"hello world!";
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    int height=findHeight(root);

    cout<<"The height of the tree is "<<height<<endl;
}
