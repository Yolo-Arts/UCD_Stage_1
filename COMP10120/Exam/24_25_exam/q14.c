#include <stdio.h>
#define TO_STRING(x) #x

int main(void) {

    printf("%s\n", TO_STRING(Hello World));

    return 0;
}