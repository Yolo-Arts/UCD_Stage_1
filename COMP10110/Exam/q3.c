#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void remove_duplicate_lowercase(char s[]);

int main(void)
{
	char str[MAX_LEN];

	/* read the string using fgets - at most MAX_LEN - 1 
	   characters will be read; the null terminator is 
	   added to the end of the string */
	printf("Enter a string:\n");
	fgets(str, MAX_LEN, stdin);


    /** Write your code here **/
    remove_duplicate_lowercase(str);

	/* display output */
	// printf("The modified string is: %s\n", str);
	
	return 0;
}

void remove_duplicate_lowercase(char s[])
{
	printf("The modified string is: ");
	int length = strlen(s);
	int lowercases[123] = {0};
	// printf("Length of string is: %d\n", length);
	// printf("%d\n", 'a');
	// printf("%d\n", 'z');
    for (int i = 0; i < length - 1; i++) {

    	if (!(s[i] >= 'a' && s[i]<= 'z')) {
    		printf("%c", s[i]);
    	} else if ((s[i] >= 'a' && s[i]<= 'z') && lowercases[s[i] - 97] != 1){
    		lowercases[s[i] - 97] = 1;
    		printf("%c", s[i]);
    	}
    }

    // for(int i = 0; i < 123; i++){
    // 	printf("%d, ", lowercases[i]);
    // 	// if (lowercases[i] == 1) {
    // 	// 	printf("hi\n");
    // 	// }
    // }
    // printf("\n %c", 97);


}
