#include <stdio.h>

// rotateArray(a, 4, 1):
// {1, 2, 3, 4} => {2, 3, 4, 1}
// rotateArray(a, 4, 2):
// {1, 2, 3, 4} => {2, 3, 4, 1}

void rotateArray(int a[], int size, int shift);

int main(void) {
    int a[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        printf("%d, ", a[i]);

    }

    printf("\n");


    rotateArray(a, 4, 3);

    for (int i = 0; i < 4; i++) {
        printf("%d, ", a[i]);

    }

    return 0;
}

// inefficient solution: shifts by a constant of 1, O(n^2) time complexity
// void rotateArray(int a[], int size, int shift) {
//     for (int j = 0; j < shift; j++) {
//         int temp = a[0];
    
//         for (int i = 1; i < size; i ++) {
//             a[i - 1] = a[i];
//         }
    
//         a[size - 1] = temp;
//     }
// }

// more efficient solution using modulo :)
void rotateArray(int a[], int size, int shift) {
    int temp = a[0];

    for (int i = 1; i < size; i ++) {
        a[i - (shift % size)] = a[i];
    }

    a[size - (shift % size)] = temp;

}