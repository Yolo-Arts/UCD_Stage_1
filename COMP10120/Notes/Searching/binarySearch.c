#include <stdio.h>

int binarySearch(int arr[], int length, int x) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            low = mid + 1;
        }

        if (arr[mid] > x) {
            high = mid - 1;
        }
    }

    return -1;
}

int main(void) {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int result = binarySearch(arr, sizeof(arr) / sizeof(arr[0]), 4);
    printf("Item is at index %d", result);


    return 0;
}