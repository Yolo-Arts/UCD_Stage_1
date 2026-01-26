#include <stdio.h>

int main(void) {

    int arrA[4][4], arrB[4][4], arrC[4][4], input = 0;

    scanf("%d", &input);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arrA[i][j] = ((j + 1) * input * (i + 1));
            printf("%d ", arrA[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arrB[i][j] = ((j + 2) * input * (i + 1));
            printf("%d ", arrB[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
            printf("%d ", arrC[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += arrC[i][j];
        }
        printf("%d ", sum);
    }

    printf("\n");
    printf("\n");

    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += arrC[j][i];
        }
        printf("%d ", sum);
    }



    return 0;
}