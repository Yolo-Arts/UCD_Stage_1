/*

Implement a function called adder that takes a variable number of integer arguments and returns their sum.

The first argument specifies the number of integers that follow.

Make sure to include any necessary libraries in your code.

For example:

Test    Result
printf("%d\n", adder(5, 2, 3, 4, 5, 6))
20
printf("%d\n", adder(3, 2, 3, 4))
9
printf("%d\n", adder(6, 5, 6, 7, 1, 1, 1))
21
printf("%d\n", adder(6, 1, 3, 5, 7, 9, 11))
36
printf("%d\n", adder(19, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1))
19

*/

#include <stdio.h>
#include <stdarg.h>

int adder(int count, ...) {

    int sum = 0;

    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++) {

        int value = va_arg(args, int);
        sum += value;
    }

    va_end(args);

    return sum;
}


int main() {
    int result1 = adder(3, 10, 20, 30);
    printf("Sum of 3 numbers: %d\n", result1); 

    int result2 = adder(5, 1, 2, 3, 4, 5);
    printf("Sum of 5 numbers: %d\n", result2); 

    int result3 = adder(0); 
    printf("Sum of 0 numbers: %d\n", result3); 

    return 0;
}


















