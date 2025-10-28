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
    int len = strlen(str);
    // printf("%d", len);
    

    
	/* display output */
	printf("The string is now ");

    for (int i = 1; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("%c", str[0]);
	return 0;
}
