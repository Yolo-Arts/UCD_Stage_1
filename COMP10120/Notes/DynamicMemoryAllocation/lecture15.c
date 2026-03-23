#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *arr;

    int size;
    printf("Emter the initial size of the array: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation faled! \n");
        return 1;
    }

    printf("Enter %d integers: \n", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements of the array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int newSize;
    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);

    arr = (int *)realloc(arr, newSize * sizeof(int));

    printf("Enter %d additional integers: \n", newSize -  size);

    for (int i = size; i < newSize; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements of the new array: \n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}