#include <stdio.h>

void function1(int a);
void function2(int b);
void function3(int c);

int main(void) {

    // initialise array of 3 pointers to functions that each take an int argument
    // and return void
    void (*f[3]) (int) = {function1, function2, function3};

    printf("Enter a number between 0 and 2. Type 3 to end: ");
    size_t choice;
    scanf("%u", &choice);

    while (choice >= 0 && choice <3) {

        (*f[choice])(choice);

        printf("Enter a number between 0 and 2. Type 3 to end: ");
        scanf("%u", &choice);
    }

    printf("Program completed");

    return 0;
}

void function1 (int a) {
    printf("You entered %d so function%d was called\n\n", a, a);
}

void function2 (int b) {
    printf("You entered %d so function%d was called\n\n", b, b);
}

void function3 (int c) {
    printf("You entered %d so function%d was called\n\n", c, c);
}