#include <stdio.h>
#include <stdbool.h>

bool palindrome(char *a, int size);

int main(void) {
    char c1[] = "Hello";
    char c2[] = "racecar";

    bool result1 = palindrome(c2, 8);

    if (result1) {
        printf("String is a palindrome");
    } else {
        printf("String is not a palindrome");
    }

    return 0;
}

bool palindrome(char *a, int size) {
    bool palindrome = true;

    for (int i = 0; i < size / 2; i++) {
        printf("%c, %c\n", a[i], a[size - i - 2]);
        if (a[i] != a[size - i - 2]) {
            palindrome = false;
            return palindrome;
        }
    }
    return palindrome;

}