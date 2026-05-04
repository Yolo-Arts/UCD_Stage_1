#include <stdio.h>

int calculate(int (*func)(int, int, int, int), int a, int b, int c, int d) {
    return func(a, b, c, d);
}

int add(int a, int b, int c, int d) {
    return a + b + c + d;
}

int main(void) {

    int result = calculate(add, 1, 2, 3, 4);
    printf("%d", result);

    return 0;
}