#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=right=nullptr;
    }
};
bool areMirrors(Node* leftTree,Node* rightTree){
    if(leftTree==nullptr && rightTree==nullptr){
        return true;
    }
    if(leftTree==nullptr || rightTree==nullptr){
        return false;
    }
    return (leftTree->data==rightTree->data)&&
        areMirrors(leftTree->left,rightTree->right);
        areMirrors(leftTree->right,rightTree->left);
}
bool isSymmetric(Node* root){
    if(root==nullptr){
        return true;
    }
    return areMirrors(root->left,root->right);
}
int main() {
    // Create a symmetric binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    // Check if the tree is symmetric
    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
