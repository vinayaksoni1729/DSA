#include <iostream>
#include <string>

using namespace std;

int main() {
    //int to string
    int a = 17291;
    string str = to_string(a);

    for (char ch : str) {
        cout << "Digit: " << ch << endl;
    }
    // string to int
    string s="100";
    int n=stoi(s);
    cout<<n;

    return 0;
}
