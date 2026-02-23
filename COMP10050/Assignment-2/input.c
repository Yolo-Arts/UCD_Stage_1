#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"

void askInput() {
    bool createGanttFromScratch = false;
    char yesOrNo[50];
    int taskAmount, startMonth, endMonth, dependencyAmount = 0;
    char taskName[MAX_NAME_LENGTH];
    int dependentTask[dependencyAmount];


    printf("Welcome to the Gantt Generator\n");
    printf("Would you like to use the test example or create your own Gantt from scratch? (yes or no)\n");
    scanf("%s", &yesOrNo);
    if (yesOrNo == "Yes") {
        printf("INSERT GANTT TEMPLATE");
    } else {
        printf("How many tasks would you like to add? (1-10)\n");
        scanf("%d", &taskAmount);

        printf("Please enter the task name\n");
        scanf("%s", &taskName);

        printf("Start Month (1-12):\n");
        scanf("%d", &startMonth);

        printf("End Month (1-12):\n");
        scanf("%d", &endMonth);

        printf("Enter how many dependencies this task has:\n");
        scanf("%d", &dependencyAmount);

        for (int i = 0; i < dependencyAmount; i++) {
            printf("Enter dependent task:\n");
            scanf("%d", &dependentTask[i]);
        }

        
    }

}

void askEditInput() {
    
}