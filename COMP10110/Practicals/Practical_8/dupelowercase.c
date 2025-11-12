#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 100

int main(void)
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];

	/* read the first string using fgets - at most 
	   MAX_LEN - 1 characters will be read; the null 
	   terminator is added to the end of the string */
	printf("Enter the first string:\n");
	fgets(str1, MAX_LEN, stdin);

	/* read the second string using fgets */
	printf("Enter the second string:\n");
	fgets(str2, MAX_LEN, stdin);


    /** Write your code here **/
    char common[26] = {};
    int index = 0;
    // printf("%d", 'c' - 97);
    
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] > 96 && str1[i] < 123) {
            // printf("It worked %c", str1[i]);
            index = str1[i] - 97;
            // printf("Index: %d\n", index);
            common[index] += 1;
        }
    }
    
    // printf("second string: \n");
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] > 96 && str2[i] < 123) {
            index = str2[i] - 97;
            // printf("Index: %d\n", index);
            common[index] += 1;
        }
    }
    
    // printf("%s", common);
    // printf("Array: \n");
    // for (int i = 0; i < 26; i++) {
    //     printf("%d, \n", common[i]);
    // }
    
    bool flag = false;
    
    printf("Common lowercase letters: ");
    for (int i = 0; common[i] < 26; i++) {
        if (common[i] >= 2) {

            
            
            printf("%c ", (char)(i + 'a'));
            flag = true;
        } 
    }
    
    if (flag == false) {
        printf("none");
    }
	
	return 0;
}
