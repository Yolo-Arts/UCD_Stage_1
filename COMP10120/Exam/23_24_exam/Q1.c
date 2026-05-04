#include <stdio.h>

int main(void) {
    int x = 5;
    int *ptr;

    ptr = &x;

    *ptr += 1;

    printf("%d", x);


    return 0;
}