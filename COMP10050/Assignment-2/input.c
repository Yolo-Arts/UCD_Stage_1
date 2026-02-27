/*
 * input.c
 *
 *  Created on: 19 Feb 2026
 *      Author: Weng
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"
#include "testGantt.h"

// struct task {
//     taskIndex
// };

void askInput() {
    bool createGanttFromScratch = false;
    bool programActive = true;
    char yesOrNo;
    int taskAmount, startMonth, endMonth, dependencyAmount = 0;
    char taskName[MAX_NAME_LENGTH];
    int dependentTask[MAX_DEPENDENCIES];


    printf("Welcome to the Gantt Generator\n");

    while (programActive) {
        printf("Would you like to use the test example or create your own Gantt from scratch? (Y/N/E(end))\n");
        scanf(" %c", &yesOrNo);

        if (yesOrNo == 'E' || yesOrNo == 'e') {
            printf("Program ended.\n");
            programActive = false;
        } else if (yesOrNo == 'Y' || yesOrNo == 'y') {
            printf("\n");
            showGantTemplate();
            printf("\n");
        } else if (yesOrNo == 'N' || yesOrNo == 'n') {


            printf("How many tasks would you like to add? (1-10)\n");
            scanf("%d", &taskAmount);

            printf("Please enter the task name\n");
            scanf("%s", taskName);

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




}

void askEditInput() {

}