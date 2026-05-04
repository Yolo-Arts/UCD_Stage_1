#include <stdio.h>

int main(void) {

    int i = 3, *j, k;
    j = &i;
    printf("%d\n", i**j*i+*j);

    return 0;
}