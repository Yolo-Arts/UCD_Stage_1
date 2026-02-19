#include <stdio.h>

void copyArray(int *a1, int *a2, int size);

int main(void){

    int a1[3] = {1, 2, 2000};
    int a2[3];
    int size = sizeof(a1) / sizeof(a1[0]);
    copyArray(a1, a2, size);
    for (int i = 0; i < size; i++) {
        printf("array 1: %d, array 2: %d\n", a1[i], a2[i]);
    }
    
    return 0;
}

void copyArray(int *a1, int *a2, int size) {
    
    for (int i = 0; i < size; i++) {
        a2[i] = a1[i];
    }
}