#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int main(void)
{
	int a[MAX_SIZE];
	int size, i;
	bool found;
	
	/* read the array size */ 
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
	int count = 0;
	
	for (j = 1; j < size; j++) {
	    if (count == 3) {
	        found = true;
	    } else if (a[j] == a[j -1]) {
	        count += 1;
	    } else {
	        count = 0;
	    }
	}
	
	if (count == 3) {
	    found = true;
	}

	
	/* Write out the result - do not edit */ 
	if (found)
	{
		printf("Array contains four consecutive equal values\n");
	}
	else
	{
		printf("Array does not contain four consecutive equal values\n");
// 		printf("Count: %d", count);
	}

	return 0;
}
