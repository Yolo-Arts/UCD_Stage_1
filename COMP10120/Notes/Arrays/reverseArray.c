#include <stdio.h>
#define MAX_SIZE 5

void reverseArray(int *a, int arraySize);

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

    reverseArray(a, MAX_SIZE);

    printf("The reversed array is: {");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d, ", a[i]);
    }
    printf("}\n");

    return 0;
}

void reverseArray(int *a, int arraySize) {

    for (int i = 0; i < arraySize/2; i++) {
        int tmp = a[i];
        a[i] = a[arraySize - 1 - i];
        a[arraySize - 1 - i] = tmp;
    }

}