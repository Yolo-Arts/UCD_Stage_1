#include <stdio.h>

int main(void) {
    char c1[] = "Hello";
    char *c2 = c1;
    c2[0] = 'A';
    // c2[i] = *(c2 + i)


    printf("%s\n", c1);
    printf("%c", 48);
    

    return 0;
}