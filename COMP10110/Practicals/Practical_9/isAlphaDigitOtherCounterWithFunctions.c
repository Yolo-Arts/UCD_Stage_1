#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 100


/** Write your code here **/

bool is_letter(char ch);
bool is_digit(char ch);

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
	
	for (int i = 0; str[i] != '\0'; i++) {
	    bool is_str = is_letter(str[i]);
	    
	    if (is_str) {
	        letters++;
	    } else {
	        bool is_num = is_digit(str[i]);
	        
	        if (is_num) {
	            digits++;
	        } else {
	            other++;
	        }
	    }
	}
	
	printf("Letters: %d\n", letters);
	printf("Digits: %d\n", digits);
	printf("Other: %d\n", other);
	
	return 0;
}


/** Write your code here **/

bool is_letter(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return true;
    } else {
        return false;
    }
}

bool is_digit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    } else {
        return false;
    }
}











