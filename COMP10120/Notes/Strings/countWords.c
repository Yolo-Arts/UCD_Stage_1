#include <stdio.h>
#include <string.h>

int countWords(char sentence[]) {
    int i = 0;
    int counter = 0;
    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            counter++;
        }
    }

    counter++;
    return counter;

}

int main(void) {
    char sentence[100];
    printf("Enter a sentence:\n");
    fgets(sentence, 100, stdin);
    int result = countWords(sentence);
    printf("The number of words in that sentence is: %d\n", result);
    return 0;
}