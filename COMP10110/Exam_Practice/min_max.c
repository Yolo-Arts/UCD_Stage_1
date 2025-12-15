#include <stdio.h>
#define MAX_SIZE 100

void min_max(int arr[], int size, int *min, int *max);

int main(void)
{
	int a[MAX_SIZE];
	int n, i;
    int min;
    int max;
	
	/* read the array size */ 
	printf("Enter the array size:\n");
	scanf("%d", &n);

	/* read array values */
	printf("Enter %d integer values:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}


	/** Write your code here **/ 
    min_max(a, n, &min, &max);

    printf("The min value is: %d\n", min);
    printf("The max value is: %d", max);
	

	return 0;
}

void min_max(int arr[], int size, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }

        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}