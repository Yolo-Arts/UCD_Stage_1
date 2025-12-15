#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

void find_union(int a1[], int size1, int a2[], int size2, int result[], int *size);

int main(void)
{
    bool found = false;
	int arr1[MAX_SIZE];
	int arr2[MAX_SIZE];
	int size1, size2, i;
	
	/* read the size of the first array */ 
	printf("Enter the size of the first array:\n");
	scanf("%d", &size1);

	/* read values into the first array */
	printf("Enter %d integer values:\n", size1);
	for (i = 0; i < size1; i++)
	{
		scanf("%d", &arr1[i]);
	}

	/* read the size of the second array */ 
	printf("Enter the size of the second array:\n");
	scanf("%d", &size2);

	/* read values into the second array */
	printf("Enter %d integer values:\n", size2);
	for (i = 0; i < size2; i++)
	{
		scanf("%d", &arr2[i]);
	}

	
	/** Write your code here **/
    int result[100] = {0};
    int size;

    find_union(arr1, size1, arr2, size2, result, &size);

    printf("The union is: ");

    for (int i = 0; i < 100; i++) {
        if (result[i] > 0) {
            printf("%d ", i);
            found = true;
        }
    }

    if (!found) {
        printf("empty");
    }
    
	

	return 0;
}


/** Write your code here **/

void find_union(int a1[], int size1, int a2[], int size2, int result[], int *size) {
    for (int i = 0; i < size1; i++) {
        if (a1[i] >= 0 && a1[i] < 100)
        result[a1[i]] = 1; 
    }

    for (int i = 0; i < size2; i++) {
        if (a2[i] >= 0 && a2[i] < 100)
        result[a2[i]] = 1; 
    }
    
}