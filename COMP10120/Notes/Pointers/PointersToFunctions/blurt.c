#include <stdio.h>

void printerr(int a, int b, int (*function)(int, int));
int add(int a, int b);
int multiply(int a, int b);

int main(void) {

    int num1, num2;
    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("Enter num2: ");
    scanf("%d", &num2);

    int choice;
    printf("Choose a function. 1 for add. 2 for multiply\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printerr(num1, num2, add);
        break;
    case 2:
        printerr(num1, num2, multiply);
        break;

    
    default:
    printf("Invalid Input \n");
        break;
    }

    return 0;
}

void printerr(int a, int b, int (*function)(int, int)) {
    int result = function(a, b);
    printf("result is : %d\n", result);
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}   
