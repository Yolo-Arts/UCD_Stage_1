#include <stdio.h>

void sumToZero(int *a, int size, int *resultA, int *resultB);

int main(void) {
    int a[4] = {1, 2, -2, 3};
    int ptrA, ptrB;
    sumToZero(a, 4, &ptrA, &ptrB);

    printf("The closest sum of pairs to zero is %d and %d\n", a[ptrA], a[ptrB]);

    return 0;
}

void sumToZero(int *a, int size, int *resultA, int *resultB) {
    int indexA = 0 ; 
    int indexB = 1;
    int closest = a[0] + a[1];

    if (closest < 0) {
        closest *= -1;
    } 

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            

            int sum = a[i] + a[j];
            if (sum < 0) {
                sum *= -1;
            }

            if (sum < closest) {
                closest = sum;
                indexA = i;
                indexB = j;
            }


        }
    }

    *resultA = indexA;
    *resultB = indexB;
    
}