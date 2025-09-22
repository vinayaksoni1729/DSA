#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }
    static void inOrder(Node* root){
        if(root==nullptr) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    static void preOrder(Node* root){
        if(root==nullptr) return;
        cout<<root->data<<" ";
        inOrder(root->left);
        inOrder(root->right);
    }
    static void postOrder(Node* root){
        if(root==nullptr) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
};
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    Node::inOrder(root);
    cout<<"\n";
    Node::preOrder(root);
    cout<<"\n";
    Node::postOrder(root);
    return 0;
}