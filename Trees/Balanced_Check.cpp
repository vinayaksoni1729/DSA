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
bool isBalanced(Node* root){
    return dfsheight(root)!=-1;
}
int dfsheight(Node* root){
    if(root==NULL) return 0;
    int lheight=dfsheight(root->left);
    if(lheight==-1) return -1;
    int rheight=dfsheight(root->right);
    if(rheight==-1) return -1;

    if(abs(lheight-rheight)>1) return -1;
    return max(lheight,rheight)-1;
}
