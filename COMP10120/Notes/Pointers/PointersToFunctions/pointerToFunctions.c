#include <stdio.h>
#define SIZE 10

void printer(int a, int b, int (*calculator)(int a, int b));
int multiplier(int a, int b);
int adder(int a, int b);

int main(void) {

    printf("Enter the First number: ");
    int numOne;
    scanf("%d", &numOne);

    printf("Enter the Second Number: ");
    int numTwo;
    scanf("%d", &numTwo);

    printf("Enter 1 for multiply or 2 for addition: ");
    int calcType;
    scanf("%d", &calcType);

    switch (calcType)
    {
    case 1:
        printer(numOne, numTwo, multiplier);
        break;

    case 2:
        printer(numOne, numTwo, adder);
        break;
    default:
        printf("That input is invalid");
        break;
    }

    return 0;
}

void printer(int a, int b, int (*calculator)(int a, int b)) {
    int result = (*calculator)(a, b);
    printf("Result is: %d", result);
}

int multiplier(int a, int b) {
    return a * b;
}

int adder(int a, int b) {
    return a + b;
}