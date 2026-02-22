#include <stdio.h>

// Function prototype as requested
int count_words(char filename[], int *total_count);

int main(void) {
    char filename[100];
    int total_count = 0;

    printf("Enter the filename:\n");

    if (scanf("%99s", filename) != 1) {
        return 0;
    }

    if (count_words(filename, &total_count)) {
        printf("The total number of words is: %d\n", total_count);
    }

    return 0;
}

int count_words(char filename[], int *total_count) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        return 0;
    }

    int ch;
    int in_word = 0; // State flag: 0 = outside word, 1 = inside word
    *total_count = 0;

    // Read file character by character until EOF
    while ((ch = fgetc(fp)) != EOF) {
        // Check if current character is one of the specified delimiters
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',' ||
            ch == '.' || ch == '?'  || ch == '!') {

            in_word = 0; // We are now outside a word
        }
        else {
            // If we were outside a word and find a non-delimiter,
            // it's the start of a new word.
            if (in_word == 0) {
                in_word = 1;
                (*total_count)++;
            }
        }
    }

    fclose(fp);
    return 1; // Return 1 for successful execution
}