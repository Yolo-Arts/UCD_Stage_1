#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void increaseAge(int *age);

int main() {

    int age = 25;
    int *pAge = &age;

    // printf("%p", pAge);

    increaseAge(pAge);

    printf("Your age is %d", age);

    return 0;
}

void increaseAge(int *age) {
    (*age)++;
}