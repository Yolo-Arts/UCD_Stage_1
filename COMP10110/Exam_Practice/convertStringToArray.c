#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char word1[] = "Jack Teong";
    int wordAmt = 0;
    char words[] = {0};
    int wordLength[] = {0};
    int counter = 0;
    // printf("%d\n", strlen(word1));

    for (int i = 0; i < strlen(word1); i++) {
        if (i == ' ' || i == '\0') {
            wordAmt++;
            wordLength[counter] = i;
            counter++;
        }
    }
    wordAmt++;

    printf("%d", wordLength[0]);

    

    return 0;
}