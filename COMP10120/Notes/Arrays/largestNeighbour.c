#include <stdio.h>

int largestNeighbour(int *a1, int size) ;

int main(void) {
    int a1[] = {1, 4, 3, 7, 1}; // 10
    int a2[] = {5, 7, 1, 5, 2}; // 12

    int result = largestNeighbour(a2, 5);
    printf("The largest neighbour is: %d\n", result);

    return 0;
}

int largestNeighbour(int *a, int size) {
    int largest = 0;

    for (int i = 1; i < size; i++) {
        if (a[i] + a[i - 1] > largest) {
            largest = a[i] + a[i - 1];
        }
    }

    return largest;
}