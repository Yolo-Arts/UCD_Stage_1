#include <stdio.h>

int sumUpTo(int num) {
    if (num == 1) {
        return 1;
    } else {
        return num + sumUpTo(num - 1);
    }
}

int main(void) {

    int result = sumUpTo(5);
    printf("%d", result);

    return 0;
}