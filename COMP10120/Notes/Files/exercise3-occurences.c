#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char myChar1, currentChar;
    int counter = 0;

    fp = fopen("exercise3.txt", "r");

    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        puts("Enter a character:");
        scanf("%c", &myChar1);

        // while (!feof(fp)) {
        //     if (fgetc(fp) == myChar1) {
        //         counter++;
        //     }
        // }

        // fgetsc always increments to the next character after running.

        while ((currentChar = fgetc(fp)) != EOF) {
            if (currentChar == myChar1) {
                counter++;
            }
        }

        fclose(fp);
    }

    // counter ++;
    printf("The number of times the character %c has occurrred is %d", myChar1, counter);


    return 0;
}