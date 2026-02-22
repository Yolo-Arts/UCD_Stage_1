/*
Write a C program to read every character from the file Wuthering_Heights.txt (the ASCII encoding version of this novel is available on Moodle) and display the number of occurrences of each lowercase and uppercase letter in the file.

The output of your program should be exactly as shown in the table below, where each row of the table should be displayed using a printf statement as follows:
   printf("%6c %6d %6c %6d\n", ...);

Note that the string "Result" should not be included in the output of your program.

Your program must follow exactly the output as shown; otherwise, you will not be awarded any marks for your work by the automatic grader.

For example:

Result
     a  38158      A    578
     b   6606      B    264
     c  11154      C    643
     d  23831      D    184
     e  63358      E    423
     f  10600      F     73
     g  10231      G    232
     h  31121      H   1564
     i  31036      I   4618
     j    386      J    164
     k   3865      K     34
     l  20139      L    523
     m  12476      M    725
     n  35401      N    336
     o  36486      O    192
     p   7650      P    109
     q    466      Q      6
     r  29173      R     56
     s  30111      S    341
     t  42209      T    745
     u  14772      U     10
     v   4545      V     25
     w  10030      W    513
     x    772      X     48
     y  10445      Y    333
     z    162      Z     35


*/

#include <stdio.h>

int main(void)
{
	int ch; /* note: use int type for ch, not char */
	int counts_lower[26] = {0};
	int counts_upper[26] = {0};

	/* open file for input */
	FILE *fp = fopen("Wuthering_Heights.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file\n");
		return -1;
	}


	/** Write your code here **/
	while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z') {
            counts_lower[ch - 'a']++;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            counts_upper[ch - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%6c %6d %6c %6d\n", (char)(i + 'a'), counts_lower[i], (char)(i + 'A'), counts_upper[i]);
    }

	/* close the file */
	fclose(fp);

	return 0;
}