#include <stdio.h>

int lucasSequence(int n) {
    if (n == 0) {
        return 2;
    } else if (n == 1) {
        return 1;
    } else {
        return lucasSequence(n - 1) + lucasSequence (n - 2);
    }
}

int main(void) {
    int result = lucasSequence(10);
    printf("%d", result);
    return 0;
}