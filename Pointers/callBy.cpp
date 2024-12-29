#include <iostream>
using namespace std;

// Function demonstrating call by reference
void func(int &x, int &y) { // Using '&' for call by reference
    int z;
    z = x; // Store the value of x in z
    x = y; // Assign the value of y to x
    y = z; // Assign the stored value of x (from z) to y
    cout << x << " " << y << endl;
}

int main() {
    // Demonstration of call by value and call by reference
    int x = 5, y = 10;
    int &z = x; // z is a reference to x (both share the same address)
    
    cout << x << " " << y << " " << z << " - here z is assigned as a reference to x" << endl;
    z = 20; // Changing z changes x, as z is a reference to x
    cout << x << " " << y << " " << z << " - here if we change the value of z, the value of x also gets changed" << endl;

    // Demonstrating the function
    x = 5, y = 10; // Resetting values
    func(x, y); // Call by reference
    cout << "After func():" << endl;
    cout << x << " " << y; // x and y are swapped in the function
}
