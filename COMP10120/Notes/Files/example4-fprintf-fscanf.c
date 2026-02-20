#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int num = 512, num2 = 12345;

    fp = fopen("myFirstFile3.txt", "w");

    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        fprintf(fp, "%d %d", num, num2);
        fclose(fp);
    }


    return 0;
}