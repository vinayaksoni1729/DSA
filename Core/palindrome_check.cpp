#include <cstdint>
#include <iostream>

bool isPalindrome(int x) {
    if (x < 0) return false; // Negative numbers are not palindromes

    int original = x;
    int reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        
        // Optional overflow check for interviews (if using large ints)
        if (reversed > (INT32_MAX - digit) / 10) return false;

        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return reversed == original;
}

int main() {
    int x;
    std::cout << "Enter number to check for palindrome: ";
    std::cin >> x;

    if (isPalindrome(x)) {
        std::cout << "Valid\n";
    } else {
        std::cout << "Invalid\n";
    }

    return 0;
}
