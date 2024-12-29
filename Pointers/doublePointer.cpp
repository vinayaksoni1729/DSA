#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an integer variable
    int a = 10;

    // Declare a pointer to an integer and assign the address of `a` to it
    int *p;
    p = &a;

    // Declare a pointer to a pointer and assign the address of `p` to it
    int **q;
    q = &p;

    // Display the addresses
    cout << "Address of a (via &a): " << &a << endl;
    cout << "Address stored in pointer p (via p): " << p << endl;
    cout << "Address of pointer p (via q): " << q << endl;

    // Display the values
    cout << "Value of a (via variable): " << a << endl;
    cout << "Value of a (via dereferencing p): " << *p << endl;
    cout << "Value of a (via double dereferencing q): " << **q << endl;

    // Modify the value of `a` using double dereferencing
    **q = 20;

    // Display the updated values
    cout << "Updated value of a (via variable): " << a << endl;
    cout << "Updated value of a (via dereferencing p): " << *p << endl;
    cout << "Updated value of a (via double dereferencing q): " << **q << endl;

    return 0;
}
