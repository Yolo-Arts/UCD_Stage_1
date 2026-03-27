#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int counter = 0;
    int capacity = 2;

    int *num = (int *)malloc(capacity * sizeof(int));

    if (num == NULL) {
        printf("Malloc failed!");
        return 1;
    }
    
    int input;
    
    while (1) {
        printf("Enter a number (-1 to quit): ");
        scanf("%d", &input);
        if (input == -1) {
            break;
        } else {
            if (counter == capacity) {
                capacity *= 2;
                int *temp = (int *)realloc(num, capacity * sizeof(int));
                
                if (temp == NULL) {
                    printf("Realloc failed!");
                    return 1;
                }

                num = temp;
            }
            
            num[counter] = input;
            counter++;
        }
    }

    printf("\nYou entered %d numbers:\n", counter);
    for (int i = 0; i< counter; i++) {
        printf("%d ", num[i]);
    }

    free(num);

    return 0;
}