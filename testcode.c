#include <stdio.h>
#include <string.h>

void removeLeadingZeros(char* str) {
    int len = strlen(str);
    int index = 0;

    // Find the index of the first non-zero character
    while (index < len && str[index] == '0') {
        index++;
    }

    // Shift all characters to the left to remove leading zeros
    for (int i = 0; i < len - index; i++) {
        str[i] = str[i + index];
    }
    str[len - index] = '\0';

    // If the string is empty, set it to "0"
    if (str[0] == '\0') {
        str[0] = '0';
        str[1] = '\0';
    }
}

int main() {
    int k;
    int x;
    printf("Enter the integer x: ");
    scanf("%d", &x);
    printf("Enter the number of digits to delete k: ");
    scanf("%d", &k);

    char str[20];
    sprintf(str, "%d", x);

    while (k > 0 && strlen(str) > 0) {
        int len = strlen(str);
        int removed = 0;
        for (int i = 0; i < len - 1; i++) {
            if (str[i] > str[i + 1]) {
                for (int j = i; j < len - 1; j++) {
                    str[j] = str[j + 1];
                }
                str[len - 1] = '\0';
                removed = 1;
                k--;
                break;
            }
        }
        if (!removed) {
            str[len - 1] = '\0';
            k--;
        }
    }

    removeLeadingZeros(str);

    printf("Resulting minimized number: %s\n", str);

    return 0;
}
