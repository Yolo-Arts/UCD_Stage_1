#include <stdio.h>
#define MAX_SIZE 4

int maxIndex(int a[], int arraySize);

int main(void) {

    int a[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Enter a number: \n");
        scanf("%d", &a[i]);
    }

    printf("The array is: {");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d, ", a[i]);
    }
    printf("}\n");


    int result = maxIndex(a, MAX_SIZE);
    printf("The max index is: %d\n", result);

    return 0;
}

int maxIndex(int a[], int arraySize) {
    int maxNumber = a[0];
    int maxIndex = 0;

    for (int i = 0; i < arraySize; i++) {
        if (a[i] > maxNumber) {
            maxNumber = a[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}
