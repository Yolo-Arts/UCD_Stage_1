#include <stdio.h>

int sumOfEven() {
    int userInput;
    printf("Enter a number: \n");
    scanf("%d", &userInput);

    if (userInput == -1) {
        return 0;
    }

    if (userInput % 2 == 0) {
        return userInput + sumOfEven();
    } else {
        return sumOfEven();
    }

}

int main(void) {

    int result = sumOfEven();
    printf("The sum of even numbers: %d\n", result);

    return 0;
}