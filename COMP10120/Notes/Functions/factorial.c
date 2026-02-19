#include <stdio.h>

int factorial(int number);

int main(void) {
    int numberInput;

    printf("Enter an integer to factorial: \n");
    scanf("%d", &numberInput);

    int result = factorial(numberInput);
    printf("The result is %d\n", result);

    return 0;
}

int factorial(int number) {
    if (number < 0) {
        return -1;
    }
    int sum = number;
    number--;
    while (number != 0) {
        sum *= number;
        number -= 1;
    }

    return sum;
}