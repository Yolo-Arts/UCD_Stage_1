#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *arr = (int *)calloc(5 ,sizeof(int));

    if (arr == NULL) {
        printf("Memory Allocation Failed!");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    int *temp = (int *)realloc(arr, sizeof(int) * 10);

    if (temp == NULL) {
        printf("Memory Allocation Failed!");
        return 1;
    } else {
        arr = temp;
    }

    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}