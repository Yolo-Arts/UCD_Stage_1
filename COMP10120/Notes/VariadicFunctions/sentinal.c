#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void print_all_strings(const char *first_str, ...);

int main(void) {

    print_all_strings("Hello", "World", "C is fun", NULL);

    return 0;
}

void print_all_strings(const char *first_str, ...) {
    if (first_str == NULL) return;

    printf("%s ", first_str);
    
    va_list args;

    va_start(args, first_str);

    while (1) {
        char *next = va_arg(args, char *);
        if (next == NULL) {
            break;
        }
        printf("%s ", next);
    }

    va_end(args);
}