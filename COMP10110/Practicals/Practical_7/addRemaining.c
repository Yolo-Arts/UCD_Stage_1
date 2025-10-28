#include <stdio.h>
#include <string.h>
#define MAX_LEN 10

int main(void)
{
	char str1[MAX_LEN];
	char str2[MAX_LEN]; 
	


	/* read the first string */
	printf("Enter the first string:\n");
	scanf("%s", str1);

	/* read the second string */
	printf("Enter the second string:\n");
	scanf("%s", str2);
	
	
	/** Write your code here **/
// 	char str3[MAX_LEN] = str2;
	int len;
	len = strlen(str1);
	int remainingLetters = MAX_LEN - len - 1; 
	strncat(str1, str2, remainingLetters);
// 	printf("%s\n", str1);
// 	printf("%d\n", remainingLetters);
	
	
	

	/* display output */
	printf("The strings are now %s and %s\n", str1, str2);

	return 0;
}