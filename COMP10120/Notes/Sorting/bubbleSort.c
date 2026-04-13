#include <stdio.h>

void bubbleSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {

    int arr[5] = {3, 2, 1, 5, 4};

    bubbleSort(arr, 5);
    
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}