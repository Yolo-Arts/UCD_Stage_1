#include <stdio.h>

int factorial(int num) {
    if (num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }

}


int main(void) {
    int result = factorial(3);
    printf("%d", result);


    return 0;
}