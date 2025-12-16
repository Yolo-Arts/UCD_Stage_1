#include <stdio.h>
#include <stdbool.h>

int main() {
    
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int filteredList[] = {0};
    int counter = 0;
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++) {
        if(numbers[i] % 2 && numbers[i] % 3 != 0) {
            filteredList[counter++] = numbers[i];
            // counter++;
        }
    }

    for (int i = 0; i < counter; i++) {
        printf("%d ", filteredList[i]);
    }

    return 0;
}