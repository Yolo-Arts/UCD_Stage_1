#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int main(void)
{
	int a[MAX_SIZE];
	int size, i, k;

	
	/* read the array size */ 
	printf("Enter the array size:\n");
	scanf("%d", &size);
	
	/* read array values */
	printf("Enter %d integer values:\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", &a[i]);
	}

	/* read the value for k */
	printf("Enter the value for k:\n");
	scanf("%d", &k);


	/** Write your code here **/
	bool found = false;
	int counter = 0;
	int b[] = {0};
	double sum = 0;

	for (i = 0; i < size; i++) {
		if (a[i] % k == 0) {
			b[counter++] = a[i];
			found = true;
		}
	}	
	

	if (found) {
		for (i = 0; i < counter; i++) {
			sum += b[i];
		}

		// printf("The sum is: %lf", sum);

		double mean = 0;

		mean = sum / counter;
		printf("The mean is: %.1lf", mean);
	} else {
		printf("The mean is: 0.0");
	}


	return 0;
}
