#include <stdio.h>

int main(void) {

    // 2 arrays inside the arr. 3 elements inside each array of the inner arrays. Holds total of 6 elements.
    // int arr[2][3];

    // imagine the array like this:
    // int arr[rows][columns]
    // where the number that replaces 'row' will be the number of rows.
    // the number that replaces 'columns' will be the number of columns. Like a table.

    // initialisation:
    int arr[2][3] = { {1, 3, 5}, {2, 4, 5}};

    /* accessing elements in the array: */ 
    /*
    arr[0][0]; // this will access '1' : the first array's first index.
    arr[1][2]; // accesses 6 : the second arrays, 3rd index (reminder that arrays are zero based.)
    */


    /* modifying arrays: */
    /*
    arr[0][2] = 7; // the array will be like this: { {1, 3, 7}, {2, 4, 5}};
    arr[1][1] = 8; // the new array will be like this { {1, 3, 7}, {2, 8, 5}};
    */

    // using for loops:

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // this nested for loop will return this:
    /*
    1 3 5 
    2 4 5 
    */

    // explanation: 
    // Outer for loop will access all the inner arrays.
    // Inner for loop will access all the items inside the inner array; each index.


    return 0;
}