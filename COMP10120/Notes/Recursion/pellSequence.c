#include <stdio.h>

int pellSequence(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return (2 * pellSequence(n - 1)) + pellSequence(n - 2);
    }
}

int main(void) {
    int result = pellSequence(21);
    printf("%d", result);
    return 0;
}