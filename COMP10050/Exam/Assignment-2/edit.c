#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 100
#define MAX_DEPENDENCIES 10

typedef struct {
    char taskName[MAX_NAME_LENGTH];
    int startMonth;
    int endMonth;
    int dependencyAmount;

    // array of dependent tasks
    int dependentTasks[MAX_DEPENDENCIES];
} Task;

void editGant(Task tasksArray[], int taskAmount) {
	char taskToEdit[MAX_NAME_LENGTH];

	printf("Please enter the task name you wish to change exactly\n");
	scanf("%49s", taskToEdit);


	for (int i = 0; i < taskAmount; i++) {
		if(strcmp(tasksArray[i].taskName, taskToEdit) == 0){
		    printf("\nPlease enter the new task name or write its old one:\n");

		    scanf("%49s", tasksArray[i].taskName); //ensures will only read max 49 characters to allow for null character and avoid overflow

		    printf("Start Month (1-12):\n");

		    scanf("%d", &tasksArray[i].startMonth);

		    printf("End Month (1-12):\n");

		    scanf("%d", &tasksArray[i].endMonth);

		    printf("Enter how many dependencies this task has:\n");
		    scanf("%d", &tasksArray[i].dependencyAmount);

		    for (int j = 0; j < tasksArray[i].dependencyAmount; j++) {
		        printf("Enter dependent task:\n");
		        scanf("%d", &tasksArray[i].dependentTasks[j]);
		    }

		    break;
		}
	 }
}