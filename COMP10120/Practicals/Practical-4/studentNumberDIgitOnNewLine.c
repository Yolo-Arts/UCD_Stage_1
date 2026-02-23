#include <stdio.h>
#include <math.h>

// 123
// 123 / 100 = 1
// 12 / 10 = 1


int main(void) {
    
    int studentNum1 = 98765432;

    int temp = studentNum1;
    int temp2 = studentNum1;

    int counter = 1;

    while (temp > 10) {
        temp /= 10;
        counter++;
    }
    printf("The amount of digits in student number is %d\n", counter);
    int num = 10000000;
    if (counter != 8) {
        printf("Invalid Input\n");
    } else {
        for (int i = 0; i < 8; i++) {
            int new = temp2/ num;
            printf("%d\n", new);
            num /= 10;
            // temp2 %= 10;
        }
    }


    return 0;
}