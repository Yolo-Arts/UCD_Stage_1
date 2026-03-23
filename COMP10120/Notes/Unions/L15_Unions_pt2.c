#include <stdio.h>

union myUnion {
    int intValue;
    float floatValue;
    char charValue;
};

int main(void) {
    union myUnion u;

    u.intValue = 10;
    printf("Integer Value: %d\n", u.intValue);

    u.floatValue = 3.14;
    printf("Float Value: %f\n", u.floatValue);

    u.charValue = 'A';
    printf("Char Value: %c\n", u.charValue);

    printf("After modifying intValue, floatValue and charValue\n");
    printf("Integer Value: %d\n", u.intValue);
    printf("Float Value: %f\n", u.floatValue);
    printf("Char Value: %c\n", u.charValue);

    return 0;
}