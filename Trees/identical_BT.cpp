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
bool areIdentical(Node* root1,Node* root2){
    if(root1==nullptr && root2==nullptr){
        return true;
    }
    if(root1==nullptr || root2==nullptr){
        return false;
    }
    return (root1->data==root2->data)&&
    areIdentical(root1->left,root2->left)&&
    areIdentical(root1->right,root2->right);
}
int main(){
        // Create two identical trees
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->left->right = new Node(5);
    root2->left->right->right = new Node(6);


    if(areIdentical(root1,root2)){
        cout<<"The trees are identical"<<endl;
    }
    else{
        cout<<"The trees are not identical"<<endl;
    }
    return 0;
}