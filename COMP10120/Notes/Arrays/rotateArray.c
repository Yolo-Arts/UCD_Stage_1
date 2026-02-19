#include <stdio.h>

// {1, 2, 3, 4} =>
// {2, 3, 4, 1}

void rotateArray(int a[], int size);

int main(void) {
    int a[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        printf("%d, ", a[i]);

    }

    printf("\n");


    rotateArray(a, 4);

    for (int i = 0; i < 4; i++) {
        printf("%d, ", a[i]);

    }

    return 0;
}

void rotateArray(int a[], int size) {
    int temp = a[0];

    for (int i = 1; i < size; i ++) {
        a[i - 1] = a[i];
    }

    a[size - 1] = temp;
}