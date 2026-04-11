#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;
    printf("How many rows?\n");
    scanf("%d", &rows);

    int **matrix = (int **)calloc(rows, sizeof(int *));

    if (matrix == NULL) {
        printf("Malloc failed!");
        exit(1);
    }

    printf("How many columns?\n");
    scanf("%d", &cols);

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));

        if (matrix[i] == NULL) {
            printf("Row Malloc failed!");
            exit(1);
        }
    }

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