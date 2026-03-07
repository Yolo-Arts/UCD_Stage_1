#include <stdio.h>

/*
n = 36435
pos 0: 5
pos 1: 3
pos 2: 4
pos 3: 6
pos 4: 3
return 0

n - 438
pos 0: 8
pos 1: 3
pos 2: 4

return 1
*/

int oddEvenPosition(int n, int counter) {
    if (!((n % 10) % 2 == counter % 2)) {
        // printf("%d\n", n % 10);
        return 0;
    } else {
        if (n < 10) {
            printf("position %d: %d\n", counter, n);
            return 1;
        } else {
            printf("position %d: %d\n", counter, n % 10);
            return oddEvenPosition(n / 10, counter + 1);
        }
    }

}

int main(void) {
    int result = oddEvenPosition(36435, 0);
    // int result = oddEvenPosition(438, 0);
    printf("Result: %d\n", result);
    return 0;
}