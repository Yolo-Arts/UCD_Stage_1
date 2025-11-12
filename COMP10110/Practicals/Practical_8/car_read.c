#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int main(void) 
{
    /* declare variables */
    FILE *fp;

    /* open file as an input file */
    fp = fopen("cars.txt", "r"); 
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1; 
    }


    /** Write your code here **/
    int id;
    char make[MAX_LEN];
    char power[MAX_LEN];
    double value;
    
    while (fscanf(fp, "%d%s%s%lf", &id, make, power, &value) == 4) {
        // printf("%s", power);
        if (!strcmp(power, "ELECTRIC") || !strcmp(power, "HYBRID")) {
            printf("{ \"id\": %d, \"make\": \"%s\", \"power\": \"%s\", \"value\": %.2lf }\n", id, make, power, value);
        }
    }

    /* close the file */
    fclose(fp);
   
    return 0;
}
