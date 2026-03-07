#include <stdio.h>

// n = 156
// 1 + 5 + 6 -> 12 -> return 1

// n = 36859
// 3 + 6 + 8 + 5 + 9 = 31 -> return 0

int evenDigitsSum(int n) {
    if (n < 10) {
        return n;
    } else {
        return (n % 10) + evenDigitsSum(n / 10);
    }
}

int main(void) {
    int result = evenDigitsSum(26859);
    printf("%d", result % 2 == 0 ? 1 : 0);

    return 0;
}