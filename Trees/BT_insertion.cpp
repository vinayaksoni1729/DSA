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
Node* insert(Node* root, int value){
    if(root==nullptr)
        return new Node(value);
    if(value<root->data)
        root->left=insert(root->left,value);
    else if(value>root->data)
        root->right=insert(root->right,value);
    return root;
}
void inorderTraversal(Node* root){
    if(root!=nullptr){
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}
int main(){
    Node* root=new Node(10);
    root = insert(root, 5);     // Insert value 5
    root = insert(root, 20);    // Insert value 20
    root = insert(root, 3);     // Insert value 3
    root = insert(root, 7);     // Insert value 7
    root = insert(root, 15);    // Insert value 15
    root = insert(root, 30);    // Insert value 30
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<endl;
    return 0;
}