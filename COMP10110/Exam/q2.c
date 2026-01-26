#include <stdio.h>

#define MAX_SIZE 100

void find_occurrences(int arr[], int size, int value, int *first, int *last);

int main(void)
{
	int a[MAX_SIZE];
	int size, i, v;
	int first_index, last_index;
	
	/* read the target value */
	printf("Enter the target value:\n");
	scanf("%d", &v);

	/* read the array size */ 
	printf("Enter the array size:\n");
	scanf("%d", &size);
	
	/* read array values */
	printf("Enter %d integer values:\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}


	/** Write your code here **/
	find_occurrences(a, size, v, &first_index, &last_index);
	
	/* write out the result */
	printf("The array is: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("The first index is: %d\n", first_index);
	printf("The last index is: %d\n", last_index);

	return 0;
}

void find_occurrences(int arr[], int size, int value, int *first, int *last)
{
	*first = 0;
	*last = 0;
	int counter = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] == value && counter == 0) {
			*first = i;
			*last = i;
			counter++;
		} else if (arr[i] == value) {
			*last = i;
		}
	}

	if (counter == 0) {
		*first = -1;
		*last = -1;
	}
}
