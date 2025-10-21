#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main(void)
{
	int a[MAX_SIZE];
	int size, i;
	bool sorted = true;

	/* read the array size - uses a do-while loop 
	   to show how the user's input can be validated, 
	   i.e. size should not be < 0 or > MAX_SIZE */ 
	do 
	{
		printf("Enter the array size:\n");
		scanf("%d", &size);
	} while (size < 0 || size > MAX_SIZE);

	/* read array values */
	printf("Enter %d integer values:\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}


	/** Write your code here **/
	int j;
	for (j = 1; j < size; j++) {
	    if (a[j - 1] > a[j]) {
	        sorted = false;
	    }
	}


	/* write out the result - do not edit */ 
	if (sorted)
	{
		printf("Array is sorted\n");
	}
	else
	{
		printf("Array is not sorted\n");
	}

	return 0;
}
