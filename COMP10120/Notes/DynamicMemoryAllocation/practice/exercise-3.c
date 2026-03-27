#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int len;
    char *name;

    printf("How many characters are in your name? ");
    scanf("%d", &len);

    // Add 1 for the '\0' null terminator
    name = (char *)malloc((len + 1) * sizeof(char));

    if (name == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Hello, %s! Your name is stored at memory address: %p\n", name, (void *)name);

    free(name);
    name = NULL; 

    return 0;
}