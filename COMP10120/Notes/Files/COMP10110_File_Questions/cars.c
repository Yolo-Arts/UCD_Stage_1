/*
Consider a text file cars.txt (available on Moodle) that contains records formatted as follows:
each line contains an id (int), a make of car (string), the car's power type (string) and the car's value (double).

Write a C program to read each record from the file and
display all records with power type "ELECTRIC" or "HYBRID" in JSON format.


For example, given the record:
  1 BMW ELECTRIC 65000.00
the corresponding JSON format is:
  { "id": 1, "make": "BMW", "power": "ELECTRIC", "value": 65000.00 }


Hint: use function fscanf(fp, "%d%s%s%lf", ...) to read each record from the file.


Your program must follow exactly the output as shown in the table below; otherwise, you will not be awarded any marks for your work by the automatic grader.

Note that the string "Result" should not be included in the output of your program.

For example:

Result
{ "id": 1, "make": "BMW", "power": "ELECTRIC", "value": 65000.00 }
{ "id": 3, "make": "Honda", "power": "ELECTRIC", "value": 47500.00 }
{ "id": 5, "make": "Nissan", "power": "HYBRID", "value": 55000.00 }
{ "id": 7, "make": "Toyota", "power": "ELECTRIC", "value": 42500.00 }
{ "id": 8, "make": "Toyota", "power": "HYBRID", "value": 40500.00 }


*/

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
