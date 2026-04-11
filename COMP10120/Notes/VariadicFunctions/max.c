#include <stdio.h>
#include <stdarg.h>

int max(int count, ...) {
    va_list args;


    va_start(args, count);
    int max = va_arg(args, int);

    for (int i = 1; i < count; i++) {
        int next = va_arg(args, int);
        if (next > max) {
            max = next;
        }
    }

    va_end(args);

    return max;

}

int main(void) {

    int result = max(5, 1, 4, 7, 31, 1);
    printf("The max in the list is %d", result);

    return 0;
}