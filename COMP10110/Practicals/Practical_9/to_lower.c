#include <stdio.h>
#define MAX_LEN 100

char to_lower(char ch);

int main(void)
{
	char str[MAX_LEN];

	/* read the string from the console using fgets - at most 
	   MAX_LEN - 1 characters will be read; the null terminator 
	   is added to the end of the string */
	printf("Enter a string:\n");
	fgets(str, MAX_LEN, stdin) ;

	
	/** Write your code here **/
	
	for (int i = 0; str[i] != '\0'; i++) {
	    str[i] = to_lower(str[i]);
	}
	
	printf("The string is now: %s", str);
	

	return 0;
}

char to_lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z') {
	    return ch + ('a' - 'A');
	}
	
	return ch;
}
