#include <stdio.h>
#include <stdlib.h>

// This program allocates memory for a name, then allocates more memory for the same name but reversed

int main (void) {

    int name_length = 0;
    char *name;

    printf("How long is your name?: ");
    scanf("%d", &name_length);
    name = (char *)malloc((name_length + 1) * sizeof(char));

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Your name is %s\n", name);


    char *reversed_name = (char *)malloc((name_length + 1) * sizeof(char));

    for (int i = 0; i < name_length; i++) {
        reversed_name[name_length - i - 1] = name[i];
    }
    reversed_name[name_length] = '\0';

    printf("Your reversed name is: %s\n", reversed_name);


    free(name);
    free(reversed_name);

    return 0;
}