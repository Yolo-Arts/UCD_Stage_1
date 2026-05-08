#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50
#define MAX_DEPENDENCIES 10

typedef struct {
    char name[MAX_LENGTH];
    int start_date;
    int end_date;

    int dependency_amount;
    int dependency_arr[MAX_DEPENDENCIES];
} Task;

void edit_task(Task tasksArray[], int taskAmount) {

    char taskToEdit[MAX_LENGTH];

    printf("Enter the task name you want to edit\n");
    scanf("%49s", taskToEdit);

    for (int i = 0; i < taskAmount; i++) {
        if (strcmp(taskToEdit, tasksArray[i].name) == 0) {

            printf("Enter the start date: \n");
            scanf("%d", &tasksArray[i].start_date);

            printf("Enter the end date:\n");
            scanf("%d", &tasksArray[i].end_date);

            printf("How many dependencies does the task have?\n");
            scanf("%d", &tasksArray[i].dependency_amount);

            for (int j = 0; j < tasksArray[i].dependency_amount; j++) {
                printf("Enter the dependent task\n");
                scanf("%d", &tasksArray[i].dependency_arr[j]);
            }
            break;   
        }
    }
}