#include <stdio.h>

int max(int n) {
    int userInput;
    printf("Enter a number: \n");
    scanf("%d", &userInput);

    if (userInput == -1) {
        return n;
    } else if(userInput > n) {
        return max(userInput);
    } else {
        return max(n);
    }
}

int main(void) {
    int result = max(0);
    printf("The max number is %d\n", result);

    return 0;
}