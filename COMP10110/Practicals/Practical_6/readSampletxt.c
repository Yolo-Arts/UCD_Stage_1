#include <stdio.h>
#define MAX_RECORDS 1000

int main(void) {

    /* declare variables */
    FILE *fp;
    int target_city, target_day;

    /* read the target city and and day */
    printf("Enter the target city code:\n");
    scanf("%d", &target_city);

    printf("Enter the target day number:\n");
    scanf("%d", &target_day);
    
    /* open file as an input file */
    fp = fopen("temps.txt", "r"); 
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1; 
    }
    
    int cityCode,day;
    double temperature;

    int count = 0;

    double meanTemp = 0;
    double minTemp = 10000;
    double maxTemp = 0;
    int found = 0;

    
    /** Write your code here **/
    while(fscanf(fp, "%d%d%lf", &cityCode, &day, &temperature) == 3) {
        // printf("%d %d %lf \n", cityCode, day, temperature);

        if (cityCode == target_city && day == target_day) {
            count++;
            if (temperature < minTemp) {
                minTemp = temperature;
                // printf("min = %4d ", minTemp);
            }
            if (maxTemp < temperature) {
                // print("%lf")
                maxTemp = temperature;
                // printf("max = %4lf ", maxTemp);
            }

            meanTemp += temperature; 
            // printf("mean = %4lf ", meanTemp);
            // printf("\n");
            found = 1;
        }
    }
    
    // printf("Full file read");

    if (found == 1) {
        printf("min = %.2lf\n", minTemp);
        printf("max = %.2lf\n", maxTemp);
        printf("mean = %.2lf\n", meanTemp / count);
        printf("count = %d\n", count);
    } else {
        printf("No records");
    }
    
    


    /* close the file */
    fclose(fp);

    return 0;
}
