#include <stdio.h>

int sumOfDigits(int n) {

    if (n < 10) {
        return n;
    } else {
        return (n % 10) + sumOfDigits(n / 10);
    }

}

int main(void) {

    // printf("%d\n", 12345 % 10);
    // printf("%d", 12345 / 10);

    int result = sumOfDigits(67);
    int result2 = sumOfDigits(9531);
    printf("%d\n", result);
    printf("%d", result2);

    return 0;
}