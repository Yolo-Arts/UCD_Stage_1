#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#define MAX_LEN 100

int main(void)
{
	char str[MAX_LEN];
	bool palindrome = false;

	/* read a string */
	printf("Enter a string:\n");
	scanf("%s", str);
	
	int len = strlen(str);
	int halfLen = len / 2;
// 	printf("Length of string: %d\n", len);
// 	printf("Length of half string: %d\n", len / 2);
	
	
	for (int i = 0; i < halfLen; i++) {
	    if (str[i] == str[len - 1 - i]) {
	        palindrome = true;
	    } else {
	        palindrome = false;
	        break;
	    }
	}
	
	
	if (strlen(str) == 1) {
	    printf("%s is a palindrome", str);
	}
    else if (palindrome) {
        printf("%s is a palindrome", str);
    } else {
        printf("%s is not a palindrome", str);
    }
}
