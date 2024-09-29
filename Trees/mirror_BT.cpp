#include <iostream>
using namespace std;

struct Node{
    /* data */
    int data;
    Node* right;
    Node* left;

    Node(int value){
        data=value;
        left=right=nullptr;
    }
};
void mirrorTree(Node* root){
    if(root==nullptr){
        return;
    }
    mirrorTree(root->left);
    mirrorTree(root->right);

    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
}
void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    // Create a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Inorder of original tree: ";
    inorder(root);
    cout<<endl;

    mirrorTree(root);
    cout<<"Inorder of mirrored tree: ";
    inorder(root);
    cout<<endl;

    return 0;
}