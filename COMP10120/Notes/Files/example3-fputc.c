#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char myChar1;

    fp = fopen("myFirstFile2.txt", "w");

    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        fputc('H', fp);
        fputc('e', fp);
        fputc('y', fp);
        fclose(fp);
    }


    return 0;
}