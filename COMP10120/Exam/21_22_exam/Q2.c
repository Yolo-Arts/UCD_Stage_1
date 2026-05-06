#include <stdio.h>

// int *get_first(int A[], int n) {
//     return A[0];
// }

// int *get_last(int A[], int n) {

//     return A[n];
// }

// int main(void) {
//     int arr[5] = {1, 2, 3, 4, 5};

//     int result = get_first(arr, 5);
//     printf("%d", result);

//     return 0;
// }

// part (d)

int coercionFunc(int a, int b) {
    return a * b;
}

int main (void) {

    double x = 3.3, y = 2.5;

    int result = coercionFunc(x, y);

    printf("Result is %d", result);

    return 0;
}


// part (d) ii

// void addOneByValue(int x) {
//     x += 1;
// }

// void addOneByReferenec(int* x) {
//     *x += 1;
// }

// int main(void) {
//     int a = 5, b = 5;

//     addOneByValue(a);
//     addOneByReferenec(&b);

//     printf("%d\n", a);
//     printf("%d", b);

//     return 0;
// }