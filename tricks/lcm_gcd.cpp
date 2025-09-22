#include <iostream>
using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int a = 4, b = 6;
  cout << "Lcm of a * b is " << lcm(a, b);
  return 0;
}