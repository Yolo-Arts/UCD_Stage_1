#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char myChar1;

    fp = fopen("myFirstFile.txt", "r");

    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        myChar1 = fgetc(fp);
        printf("The character that was read is: %c \n", myChar1);
        myChar1 = fgetc(fp);
        printf("The character that was read is: %c \n", myChar1);
        fclose(fp);
    }


    return 0;
}