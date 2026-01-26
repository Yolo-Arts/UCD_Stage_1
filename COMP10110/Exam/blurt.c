#include <stdio.h>
#include <stdbool.h>

int main() {

	int ch = 0;
	int counter = 0;

	char test[] = "Hello !!     \n  Is     that   you,Batman??   \nAh ,  yes.We     meet   again  !  !  !        \n   Now  ,take   me to    the  bat     cave... ";

	while(test[ch] != '\0') {
		// printf("%c", test[ch]);

		if (test[ch] == ' ' && test[ch + 1] != ' ') {
			counter += 1;
		}

		ch++;
	}

	printf("Number of words: %d", counter);

	return 0;
}