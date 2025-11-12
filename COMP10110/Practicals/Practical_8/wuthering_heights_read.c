#include <stdio.h> 

int main(void) 
{
// 	int ch; /* note: use int type for ch, not char */
// 	int counts_lower[26] = {0};
// 	int counts_upper[26] = {0};

	/* open file for input */
	FILE *fp = fopen("Wuthering_Heights.txt", "r");  
	if (fp == NULL)
	{
		printf("Error opening file\n");
		return -1; 
	}


	/** Write your code here **/
	char str1[100];
	
	
	char common[26] = {};
    int index = 0;
    // printf("%d", 'c' - 97);
    
    
	while(fscanf(fp, "%s", str1) == 1) {
	   // printf("%s", str1);
        for (int i = 0; str1[i] != '\0'; i++) {
            if (str1[i] > 96 && str1[i] < 123) {
                
                // printf("It worked %c", str1[i]);
                index = str1[i] - 97;
                // printf("Index: %d\n", index);
                common[index] += 1;
            }
        }
	}
    
    
    for (int i = 0; i < 26; i++) {
        // printf("%6c %6d", (char)(i + 'a'), common[i]);
        // printf("%6c %6d\n", (char)(i + 'A'), common[i]);
        printf("%6d %6d", i, common[i]);
        printf("%6d %6d\n", i, common[i]);
    }
    // bool flag = false;
    
    // printf("Common lowercase letters: ");
    // for (int i = 0; common[i] < 26; i++) {
    //     if (common[i] >= 2) {

            
            
    //         printf("%c ", (char)(i + 'a'));
    //         flag = true;
    //     } 
    // }
    
    // if (flag == false) {
    //     printf("none");
    // }

	/* close the file */
	fclose(fp);

	return 0; 
}