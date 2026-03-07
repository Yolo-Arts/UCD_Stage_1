#include <stdio.h>

void oneToN(int n) {
    if (n == 1) {
        printf("%d", n);
    } else {
        printf("%d", n);
        oneToN(n - 1);
    }
}

int main(void) {

    oneToN(5);

    return 0;
}