#include <stdio.h>

// I interpreted the question wrong >:(
// this code is unfinished.


int maxNumber(int number);

int main(void) {

    int number = 0;
    printf("Enter a number: \n");
    scanf("%d", &number);



    return 0;
}

int maxNumber(int number) {
    int temp = number;
    int counter = 0;

    // 123
    // printf("2 %% 10 is %d", 12 / 10); -> 1

    while (temp > 9) {
        counter++;
        temp /= 10;
        printf("Number is: %d\n", temp);
    }

    counter++;

    printf("%d", counter);

    int max = 0;

    if (counter == 1) {
        return number;
    } 
}