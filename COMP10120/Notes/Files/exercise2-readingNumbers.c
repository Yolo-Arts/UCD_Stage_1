#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int myNum, myPower;

    fp = fopen("exercise2.txt", "r");

    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        while (fscanf(fp, "%d %d", &myNum, &myPower) != EOF) {
            printf("%d, %d\n", myNum, myPower);
        }
        fclose(fp);
    }


    return 0;
}