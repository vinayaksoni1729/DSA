#include <climits>
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
    if(root==nullptr) return -1;
    int leftHeight=findHeight(root->left);
    int rightHeight=findHeight(root->right);
    return 1+max(leftHeight,rightHeight);
}
int countNodes(Node* root){
    if(root==nullptr) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int countLeaves(Node* root){
    if(root==nullptr) return 0;
    if(root->left==nullptr && root->right==nullptr) return 1;
    return countLeaves(root->left)+ countLeaves(root->right);
}
int sumOfAll(Node* root){
    if(root==nullptr) return 0;
    return root->data + sumOfAll(root->left)+sumOfAll(root->right);
}
int maxValue(Node* root){
    if(root==nullptr) return INT_MIN;
    return max(root->data,max(maxValue(root->left),maxValue(root->right)));
}
int minValue(Node* root){
    if(root==nullptr) return INT_MAX;
    return min(root->data,max(minValue(root->left),minValue(root->right)));
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    int height=findHeight(root);
    int tNode=countNodes(root);
    cout<<"The height of the  bt tree is "<<height<<" and total nodes are "<<tNode<<endl;
    cout<<"Sum of all nodes is -"<<sumOfAll(root)<<" max value is "<<maxValue(root)<<" and min value is "<<minValue(root);
}
