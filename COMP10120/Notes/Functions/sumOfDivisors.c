#include <stdio.h>

int sumOfDivisors(int num);
int optimizedSumOfDivisors(int num);

int main(void) {
    int number, result = 0;
    printf("Enter a number: \n");
    scanf("%d", &number);
    // result = sumOfDivisors(number);
    result = optimizedSumOfDivisors(number);
    printf("The sum of divisors is: %d\n", result);
    return 0;
}

// according to MATH, we do not need to check all the 'num' as the second highest divisor will always be half of num.
// 12 -> 1, 2, 3, 4, 6, 12

int sumOfDivisors(int num) {
    int sum = 0;
    for (int i = 1; i <= num/2; i++) {
        if (num % i == 0) {
            // printf("%d, ", i);
            sum += i;
        }
        
    }
    return sum + num;
}

// if we want to optimise this further:
// we can check the pairs.
// For example:
// 1 and 12 are a pair -> 12/1 = 12
// 2 and 6 are a pair -> 12/2 = 6
// checking for pairs will make it so that we only need to check up to the
// sqrt(num)
// 1, 2, 4, 8, 16 -> Only need to check up to 4

int optimizedSumOfDivisors(int num) {
    int i;
    int sum = 0;
    for (i = 1; i * i < num; i++) {
        if (num % i == 0) {
            // printf("%d, ", i);
            sum += i + (num / i);
        }
        
    }
    
    if (i * i == num ) {
        sum += i;
    }

    return sum;
}

