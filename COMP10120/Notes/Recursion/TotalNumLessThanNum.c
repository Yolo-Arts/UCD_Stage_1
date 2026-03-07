#include <stdio.h>

// num = 5
// 6, 8, 10, 3, 1, 7, -1
// return 2

int totalSmaller(int num) {
    int inputUser;
    printf("Please enter a number: \n");
    scanf("%d", &inputUser);

    if (inputUser == -1) {
        return 0;
    } else if (inputUser < num) {
        return 1 + totalSmaller(num);
    } else {
        return totalSmaller(num);
    }

}

int main(void) {
    int result = totalSmaller(4);

    printf("The amount of smaller numbers is %d", result);

    return 0;
}