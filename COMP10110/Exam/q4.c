#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 100

int count_words(char filename[], int *total_count);

int main (void)
{
	char filename[MAX_LEN];
	int count;

	/* read the filename */
	printf("Enter the filename:\n");
	scanf("%s", filename);

	/* display output */

	int ch;
	int counter = 0;
	bool lastCharWasASpace = false;
	// bool charIsPunctuation = false;
	bool charIsWord = false;
	FILE *fp;

	fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("Error opening file :(\n");
		return 0;
	}

	while ((ch = fgetc(fp)) != EOF) {
		// if (ch == '.' && !charIsPunctuation) {
		// 	counter -= 1;
		// 	charIsPunctuation = true;
		// }

		if (ch == ' ' && !lastCharWasASpace){
			counter++;
			lastCharWasASpace = true;
		} 
		else if (ch == '\n') {
			counter++;
		} 
		else {
			lastCharWasASpace = false;
			// charIsPunctuation = false;
		}
	}



	if (count_words(filename, &count))
	{
		printf("The total number of words is: %d\n", counter);
	}
	else
	{
		printf("Error opening file\n");
	}

	return 0;
}

int count_words(char filename[], int *total_count)
{
	int ch;
	int counter = 0;
	FILE *fp;

	fp = fopen("file_1.txt", "r");

	if (fp == NULL) {
		printf("Error opening file :(\n");
		return 0;
	}

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == ' '){
			(*total_count)++;
			counter++;
		}
	}

	fclose(fp);

	return counter;
}