#include <stdio.h>
#include <math.h>

void decimalToBinary(int decInput);

int main(void) {
    decimalToBinary(17);
    return 0;
}

void decimalToBinary(int decInput) {
    int n = decInput, counter = 0;
    int numbers[100] = {};
    while (n != 0) {
        // printf("%d", n % 2);
        numbers[counter] =  n % 2;
        counter++;
        n /= 2;
    }

    printf("counter: %d\n", counter);

    for (int i = counter - 1; i > 0; i--) {

        printf("%d", numbers[counter]);

    }

}