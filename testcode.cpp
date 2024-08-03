#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
 
int main() {
    Node nodes[3];  // Array of 3 nodes

    // Assign data and set up links
    nodes[0].data = 1;
    nodes[0].next = &nodes[1];
    nodes[1].data = 2;
    nodes[1].next = &nodes[2];
    nodes[2].data = 3;
    nodes[2].next = NULL;

    printList(&nodes[0]);

    return 0;
}
