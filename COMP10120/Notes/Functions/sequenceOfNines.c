#include <stdio.h>

void sequenceOfNines(int length);

int main(void) {
    int numberOfNines;
    printf("How many nines do you want printed?\n");
    scanf("%d", &numberOfNines);
    sequenceOfNines(numberOfNines);
    return 0;
}

void sequenceOfNines(int length) {

    for (int i = 0; i < length; i++) {
        printf("9");
    }
}