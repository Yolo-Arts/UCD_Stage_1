#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows = 3, cols = 3;

    int **matrix = (int **)calloc(rows, sizeof(int *));

    if (matrix == NULL) {
        printf("Malloc failed!");
        free(matrix);
        return -1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
    }

    matrix[0][1] = 10;
    matrix[2][2] = 20;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}