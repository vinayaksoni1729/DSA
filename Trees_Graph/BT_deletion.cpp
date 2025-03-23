#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;  // Using 'data' instead of 'key' as we did before
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
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

// Function to find the minimum value node in a tree
Node* findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// Function to delete a node from the binary tree
Node* deleteNode(Node* root, int key) {
    // Base case: If the tree is empty
    if (root == nullptr)
        return root;

    // Recur down the tree
    if (key < root->data)
        root->left = deleteNode(root->left, key);   // Key lies in the left subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key); // Key lies in the right subtree
    else {
        // Node found: This is the node to be deleted
        
        // Case 1: Node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        
        // Case 2: Node has one child (right or left)
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 3: Node has two children
        // Find the inorder successor (smallest node in right subtree)
        Node* temp = findMin(root->right);
        
        // Replace root's data with the inorder successor's data
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

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

    // Print inorder traversal before deletion
    cout << "Inorder Traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    // Delete node with value 20
    root = deleteNode(root, 20);

    // Print inorder traversal after deletion
    cout << "Inorder Traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
