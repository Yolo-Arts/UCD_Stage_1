#include <stdio.h>

void increment(int *number);

int main(void) {
    int x = 10;
    printf("x is %d\n", x);
    increment(&x);
    printf("x is now %d", x);
    return 0;
}

void increment(int *number) {
    *number = *number + 1;
}