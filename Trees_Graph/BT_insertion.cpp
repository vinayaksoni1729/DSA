#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data; // Using 'data' instead of 'key' as we did before
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a new node in the binary tree
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node and return it
    if (root == nullptr)
        return new Node(value);

    // If the value is less than the root's data, insert in left subtree
    if (value < root->data)
        root->left = insert(root->left, value);
    
    // If the value is greater than the root's data, insert in right subtree
    else if (value > root->data)
        root->right = insert(root->right, value);

    // Return the unchanged root pointer
    return root;
}

// Function for inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);   // Traverse left subtree
        cout << root->data << " ";      // Visit root
        inorderTraversal(root->right);  // Traverse right subtree
    }
}

// Main function to test the code
int main() {
    // Create the following binary tree:
    //        10
    //       /  \
    //      5    20
    //     / \   / \
    //    3   7 15  30

    Node* root = new Node(10);  // Create root node with value 10
    root = insert(root, 5);     // Insert value 5
    root = insert(root, 20);    // Insert value 20
    root = insert(root, 3);     // Insert value 3
    root = insert(root, 7);     // Insert value 7
    root = insert(root, 15);    // Insert value 15
    root = insert(root, 30);    // Insert value 30

    // Print inorder traversal of the binary tree
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
