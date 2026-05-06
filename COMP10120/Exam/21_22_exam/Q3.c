#include <stdio.h>

int main(void) {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", (i * 2 + 2) + (j * 2));
        }
        printf("\n");
    }

    return 0;
}