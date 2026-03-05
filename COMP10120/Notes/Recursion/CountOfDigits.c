#include <stdio.h>

int countOfDigits(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + countOfDigits(n / 10);
    }
}


int main(void) {

    int result = countOfDigits(123456789);
    printf("%d", result);

    return 0;
}