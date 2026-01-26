#include <stdio.h>
const int GRID_SIZE = 4;

int main(void) {
    int testInput = 0;
    scanf("%d", &testInput);

    int arrayA[4];
    int counter = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        arrayA[i] = testInput * counter;
        counter++;
    }

    for (int i = 0; i < 4; i++) {
        printf("%d", arrayA[i]);
    }
}