#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int main(void)
{
	char str[MAX_LEN];

	/* read a string */
	printf("Enter a string:\n");
	scanf("%s", str);

	
	/** Write your code here **/
	int letters = 0;
	int digits = 0;
	int other = 0;
	
	for (int i = 0; i < strlen(str); i++) {
	    if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
	        letters++;
	    } else if (str[i] >= 48 && str[i] <= 57) {
	        digits++;
	    } else {
	        other++;
	    }
	}
	
	printf("Letters: %d\n", letters);
	printf("Digits: %d\n", digits);
	printf("Other: %d\n", other);
	
	
	return 0;
}
