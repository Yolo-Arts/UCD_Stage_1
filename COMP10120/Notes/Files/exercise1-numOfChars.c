#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int numOfChars = 0;
    int numOfLines = 0;
    char myChar;

    fp = fopen("exercise1.txt", "r");

    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        while ( (myChar = fgetc(fp)) != EOF) {
            if (myChar != ' ' && myChar != '\n') { // counts only characters, no whitespace or \n.
                numOfChars++;
            }

            if (myChar == '\n') {
                numOfLines++;
            }
        }
        fclose(fp);
    }

    printf("Number of characters: %d\n", numOfChars);
    printf("Number of lines: %d\n", numOfLines);


    return 0;
}