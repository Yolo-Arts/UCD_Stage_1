#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main(void)
{
	int a[MAX_SIZE];
	int size, i;
	bool consecutive = true;

	/* Read the array size */ 
	printf("Enter the array size:\n");
	scanf("%d", &size);
	
	/* Read array values */
	printf("Enter %d integer values:\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}

    
    /** Write your code here **/
    int j;
    int count = 1;
    int moddedArray[MAX_SIZE] = {};
    
    moddedArray[0] = a[0];
    
    for (j = 1; j < size; j++) {
        if (a[j] != moddedArray[count - 1]) {
            moddedArray[count] = a[j];
            count++;
        }
    }
    

	/* Write out the result - do not edit */ 
	printf("Modified array: ");
	for(i = 0; i < count; i++)
	{
		printf("%d ", moddedArray[i]); 
	}
	printf("\n");

	return 0;
}
