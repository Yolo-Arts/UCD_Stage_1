#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int num;

    fp = fopen("exercise2.txt", "w");

    if (fp == NULL) {
        printf("Opening of file has failed!");
    } else {
        printf("Enter a number: \n");
        scanf("%d", &num);
        for (int i = 1; i <= num; i++) {
            fprintf(fp, "%d %d\n", i, i*i);
        }
        fclose(fp);
    }


    return 0;
}