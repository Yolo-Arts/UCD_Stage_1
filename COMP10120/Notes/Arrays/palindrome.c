#include <stdio.h>
#include <stdbool.h>

bool palindrome(int *a, int size);

int main(void) {
    int a1[5] = {1, 2, 3, 2, 1};
    int a2[3] = {1, 3, 1};
    int a3[4] = {1, 4, 2, 1};
    int a4[4] = {1, 2, 2, 1};

    bool result1 = palindrome(a4, 4);

    if (result1) {
        printf("Array is a palindrome");
    } else {
        printf("Array is not a palindrome");
    }

    return 0;
}

bool palindrome(int *a, int size) {
    bool palindrome = true;

    for (int i = 0; i < size / 2; i++) {
        printf("%d, %d\n", a[i], a[size - i - 1]);
        if (a[i] != a[size - i - 1]) {
            palindrome = false;
            return palindrome;
        }
    }
    return palindrome;

}