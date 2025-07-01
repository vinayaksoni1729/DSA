#include <iostream>

void print_fibonacci_up_to(int limit) {
    int prev = 0, curr = 1;

    while (prev <= limit) {
        std::cout << prev << "\n";
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
}

int main() {
    int n;
    std::cout << "Enter limit for Fibonacci series: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Please enter a non-negative number.\n";
        return 1;
    }

    print_fibonacci_up_to(n);
    return 0;
}
