#include <stdio.h>
#define MAX_SIZE 11

// this code will print out the multiplicaton times table from 1-10

int main(void) {

    int a[MAX_SIZE][MAX_SIZE];

    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 1; j < MAX_SIZE; j++) {
            a[i][j] = i * j;
            printf("%5d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}