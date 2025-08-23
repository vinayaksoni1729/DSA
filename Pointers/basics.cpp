#include <iostream>
using namespace std;
int main() {
    int a=10;
    int *p=&a;  
    // '*' here means "p is a pointer to int"
    // '&a' means "address of a", so p now stores where a lives
    cout<<"Value of a- "<<a<<"\n";
    cout<<"Address of a- "<<p<<"\n";
    //referencing it
    int &b=a;
    // '&' here is part of the type, meaning "b is a reference to a"
    // references are just another name for an existing variable
    cout<<"Value of unchanged a- "<<b<<"\n";
    b=15;
    cout<<"Value of b- "<<b<<"\n";
    cout<<"Value of changed a- "<<a<<"\n";
    //dereferencing
    *p=20;
    // '*' here is "dereference", go to the address stored in p
    // changes the value at that address (which is a)
    cout<<"Value of a reading from pointer- "<<*p<<"\n";
    cout<<"Value of again changed a- "<<a<<"\n";
    return 0;
}