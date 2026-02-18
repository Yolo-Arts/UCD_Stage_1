#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

int main(void) {
    int a[MAX_SIZE];
    bool sorted = true;

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("Enter a number: \n");
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < MAX_SIZE; i++) {
        if (a[i] < a[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) {
        printf("The list is sorted :)");
    } else {
        printf("The list is not sorted :(");
    }

    return 0;
}