/*
Write a C program to count how many times a substring occurs in a file where the case of the characters is ignored.

Use the fgets function to read each line in turn from the file and the scanf function to read the substring and the filename from the console.


For example, given the file batman.txt (available on Moodle) which contains:

Hello, Batman! We meet again!
No acrobatics or combat will save you now!!
Now, take me to the bat cave...

here is a sample run of the program:

Enter the substring:
bat
Enter the filename:
batman.txt
The substring bat occurs 4 times

Your program must follow exactly the input and output as shown; otherwise, you will not be awarded any marks for your work by the automatic grader.

Additional examples (test cases) are shown in the table below. Marks are awarded for each of the test cases that your program passes.

For example:

Input	Result
bat
batman.txt
Enter the substring:
Enter the filename:
The substring bat occurs 4 times
BAT
batman.txt
Enter the substring:
Enter the filename:
The substring BAT occurs 4 times
bats
batman.txt
Enter the substring:
Enter the filename:
The substring bats occurs 0 times
batman
batman.txt
Enter the substring:
Enter the filename:
The substring batman occurs 1 times
Heathcliff
Wuthering_Heights.txt
Enter the substring:
Enter the filename:
The substring Heathcliff occurs 476 times
Heath
Wuthering_Heights.txt
Enter the substring:
Enter the filename:
The substring Heath occurs 493 times


*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 500

int main(void)
{
	char filename[MAX_LEN], sub[MAX_LEN];
	int count = 0;
	FILE *fp;

	/* read the substring using scanf; the null terminator is
	   added to the end of the string */
	printf("Enter the substring:\n");
	scanf("%s", sub);

	/* read the filename using scanf; the null terminator is
	   added to the end of the string */
	printf("Enter the filename:\n");
	scanf("%s", filename);

	/* open the file for input */
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}


    /** Write your code here **/

    char lower_sub[MAX_LEN];
    int sub_len = strlen(sub);
    for (int i = 0; i < sub_len; i++) {
        lower_sub[i] = tolower(sub[i]);
    }
    lower_sub[sub_len] = '\0';

    char line[MAX_LEN];
    char lower_line[MAX_LEN];


    while (fgets(line, MAX_LEN, fp) != NULL) {
        int line_len = strlen(line);
        for (int i = 0; i < line_len; i++) {
            lower_line[i] = tolower(line[i]);
        }
        lower_line[line_len] = '\0';

        for (int i = 0; i <= line_len - sub_len; i++) {
            int is_match = 1;
            for (int j = 0; j < sub_len; j++) {
                if (lower_line[i + j] != lower_sub[j]) {
                    is_match = 0;
                    break;
                }
            }
            if (is_match) {
                count++;
            }
        }
    }

	/* close the file */
	fclose(fp);

	/* display output */
	printf("The substring %s occurs %d times\n", sub, count);

	return 0;
}
