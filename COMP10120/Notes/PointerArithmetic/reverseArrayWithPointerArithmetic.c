#include <stdio.h>

void reverseArray(int *arr, int size);

int main(void) {
    int myArray[9] = {9,5,6,2,1,8,2,4,5};

    reverseArray(myArray, 9);

    for (size_t i = 0; i < 9;i++) {
        printf("%d, ", myArray[i]);
    }

    return 0;
}

void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    int temp = 0;
    while(start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}