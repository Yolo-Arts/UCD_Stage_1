#include <stdio.h>

union number {
    int x;
    double y;
};

int main(void) {

    union number value;

    value.x = 100;
    printf("%s\n%s\n%s\n %d\n\n%s\n %lf\n\n\n", "Put 100 in the integer member", "and print both members.", "int:", value.x, "double:", value.y);

    value.y = 100;
    printf("%s\n%s\n%s\n %d\n\n%s\n %lf\n\n\n", "Put 100 in the integer member", "and print both members.", "int:", value.x, "double:", value.y);

    return 0;
}