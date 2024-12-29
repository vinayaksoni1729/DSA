#include <iostream>
using namespace std;

int main() {
    // `*` denotes a pointer to a variable (it stores the memory address).
    // `&` gets the memory address of a variable.

    int a = 10;        // Declare and initialize an integer variable
    int &c = a;        // `c` is a reference to `a` (alias for `a`)
    int *p;            // Declare a pointer to an integer
    p = &a;            // Assign the address of `a` to pointer `p`

    // Display the value of `a` using the variable and its reference
    cout << "Value of a (via variable): " << a << endl;
    cout << "Value of a (via reference): " << c << endl;

    // Display the address of `a` and the address stored in pointer `p`
    cout << "Address of a (via &a): " << &a << endl;
    cout << "Address stored in pointer p: " << p << endl;

    // Modify the value of `a` using the pointer `p`
    *p = 20;           // Dereference `p` to access and modify the value of `a`

    // Display the updated value of `a` using the variable and pointer
    cout << "Updated value of a (via variable): " << a << endl;
    cout << "Updated value of a (via dereferencing pointer): " << *p << endl;

    // Display the address of `a` and the address of pointer `p`
    cout << "Address of a (via &a): " << &a << endl;
    cout << "Address of pointer p (via &p): " << &p << endl;

    return 0;
}
