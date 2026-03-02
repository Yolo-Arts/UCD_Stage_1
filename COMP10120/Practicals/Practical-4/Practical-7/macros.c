/*
Write a C program that defines a macro named MAX_NUM, which takes two numbers as arguments and returns the maximum of the two.

In the main function, read two numbers from standard input using scanf (without displaying a prompt) and use the MAX_NUM macro to determine the maximum.

Finally, print the result as shown in the test case.

Note: Do not prompt the user for input; simply use scanf to read the numbers.

For example:

Input    Result
10 20
The maximum of 10 and 20 is: 20
30 10
The maximum of 30 and 10 is: 30

*/

#include <stdio.h>

#define max(a, b) ( ((a) > (b)) ? (a) : (b) )


int main(void) {
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    int result = max(num1, num2);

    printf("The maximum of %d and %d is: %d", num1, num2, result);

    return 0;
}