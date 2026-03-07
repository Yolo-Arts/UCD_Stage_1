#include <stdio.h>

int totalChars(char c) {
    char userInput;
    printf("Enter a character: \n");
    scanf(" %c", &userInput);

    if (userInput == '$') {
        return 0;
    } else if (userInput == c) {
        return 1 + totalChars(c);
    } else {
        return totalChars(c);
    }
}


int main(void) {

    int result = totalChars('a');
    printf("The number of chars in the sequence is %d\n", result);


    return 0;
}