#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char word1[] = "Hello";
    int size = strlen(word1);
    char result[size + 1];

    printf("Size of string: %d\n", size);

    for(int i = 0; i < size; i++) {
        result[i] = word1[size - i - 1];
    }
    result[size] = '\0';

    printf("%s\n", word1);
    printf("Reversed string: %s", result);

    return 0;
}