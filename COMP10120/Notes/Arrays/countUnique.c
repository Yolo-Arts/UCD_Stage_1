#include <stdio.h>
#include <stdbool.h>

// this program returns the unique items (no dupes)

int returnUnqiue(int *a, int size, int *uniqueArr);

int main(void) {
    int a1[] = {1, 2, 2, 3, 4, 5, 5, 5, 6, 9}; // -> {1, 3, 4, 6, 9}
    int uniqueArr[] = {};

    int uniqueArrSize = returnUnqiue(a1, sizeof(a1) / sizeof(a1[0]), uniqueArr);

    for(int i = 0; i < uniqueArrSize; i++) {
        printf("%d, ", uniqueArr[i]);
    }


    return 0;
}

int returnUnqiue(int *a, int size, int *uniqueArr) {
    // int notUniqueCounter = 0;
    // int notUnique[] = {};
    int counter = 0;

    for (int i = 0; i < size; i++) {
        bool unique = true;
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                // notUnique[notUniqueCounter] == a[j];
                unique = false;
                break;
            }

        }

        if (unique) {
            uniqueArr[counter] = a[i];
            counter++;
        }
    }

    return counter;
}