#include <stdio.h>

int main(void) {

    FILE *fp;
    FILE *reportFp;

    fp = fopen("grades.txt", "r");
    reportFp = fopen("report.txt", "w");

    if (fp  == NULL || reportFp == NULL) {
        printf("File cannot be opened");
    } else {
        char name[30];
        double mathScore, scienceScore;
        while (fscanf(fp, "%s%lf%lf", name, &mathScore, &scienceScore) == 3) {
            double average = (mathScore + scienceScore) / 2;
            fprintf(reportFp, "%-30s %10.2lf\n", name, average);
        }

        fclose(fp);
        fclose(reportFp);
    }


    return 0;
}