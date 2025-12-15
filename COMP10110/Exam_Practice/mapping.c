#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int i;
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (i = 0; i < size; i++) {
        numbers[i] = pow(numbers[i], 2);
    }

    for (i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}

