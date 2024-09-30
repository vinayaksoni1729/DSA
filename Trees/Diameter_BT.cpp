#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

int height(Node* root, int& diameter){
    if(root==NULL){
        return 0;
    }
    int leftheight=height(root->left,diameter);
    int rightheight=height(root->right,diameter);
    diameter=max(diameter,leftheight+rightheight);
    return max(leftheight,rightheight)+1;
}
int diameterbtee(Node* root){
    int diameter=0;
    height(root,diameter);
    return diameter;
}

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \     
    //    4   5    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Diameter of the tree: " << diameterbtee(root) << endl;

    return 0;
}
