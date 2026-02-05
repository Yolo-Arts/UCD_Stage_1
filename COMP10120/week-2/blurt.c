#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int number = 0;
    bool isEven = true;

    printf("Enter a number\n");
    scanf("%d", &number);

    if (!number) {
        printf("no number entered");
        return 0;
    }

    while (isEven) {

        if (number == false) {
            isEven = false;
            break;
        }

        printf("Enter a number\n");
        scanf("%d", &number);
    }


    return 0;
}