#include <iostream>
#include <string>

using namespace std;

int main() {
    int a = 17291;
    string str = to_string(a);

    for (char ch : str) {
        cout << "Digit: " << ch << endl;
    }

    return 0;
}
