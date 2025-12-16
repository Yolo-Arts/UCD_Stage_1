#include <stdio.h>
#include <stdbool.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    bool found = false;
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Size: %d\n", size);

    int index;
    int search;

    printf("Enter a number: ");
    scanf("%d", &search);
    printf("The number you have searched for is %d\n", search);

    for (int i = 0; i < size; i++) {
        if (search == numbers[i]) {
            index = i;
            found = true;
            break;
        }
    }
    
    if (found) {
        printf("Number found at index %d\n", index);
    } else {
        printf("Number not found");
    }

    return 0;
}