#include <stdio.h>
#define MAX_LEN 100

int main(void)
{
	char msg[MAX_LEN];
	int k;
	
	/* read the string using fgets - at most MAX_LEN - 1
	   characters will be read; the null terminator is 
	   added to the end of the string */
	printf("Enter a string:\n");
	fgets(msg, MAX_LEN, stdin);

	/* read k */
	printf("Enter a value for k:\n");
	scanf("%d", &k);


    /** Write your code here **/
    for (int i = 0; msg[i + 1] != '\0'; i++) {
        if (msg[i] < 97) {
            msg[i] += 0;
        
        } else {
            if ('a' + (msg[i] - 'a' + k) % 26 < 97) {
                msg[i] = ('a' + (msg[i] - 'a' + k) % 26) + 26;
            } else {
                
                msg[i] = 'a' + (msg[i] - 'a' + k) % 26;
            }
        }
    }
    

	/* display output */
	printf("The encrypted message is: %s", msg);
		
	return 0;
}