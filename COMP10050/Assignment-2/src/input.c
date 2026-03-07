/*
 * input.c
 *
 *  Created on: 5 Mar 2026
 *      Author: annie
 */

/*
 * input.c
 *
 *  Created on: 19 Feb 2026
 *      Author: Weng Kiat
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"
#include "testGantt.h"
#include "edit.h"
#include "test.h"
#include "display.h"



void populateTasks(Task *t) {
    printf("Please enter the task name\n");
    fflush(stdout);
    scanf("%49s", t->taskName); //ensures will only read max 49 characters to allow for null character and avoid overflow

    printf("Start Month (1-12):\n");
    fflush(stdout);
    scanf("%d", &t->startMonth);

    printf("End Month (1-12):\n");
    fflush(stdout);
    scanf("%d", &t->endMonth);

    printf("Enter how many dependencies this task has:\n");
    fflush(stdout);
    scanf("%d", &t->dependencyAmount);

    for (int i = 0; i < t->dependencyAmount; i++) {
        printf("Enter dependent task:\n");
        fflush(stdout);
        scanf("%d", &t->dependentTasks[i]);
    }
}

void askInput() {
    // bool createGanttFromScratch = false;

    // flag to ensure program runs until stopped.
    bool programActive = true;

    char yesOrNo;

    // int taskAmount, startMonth, endMonth, dependencyAmount = 0;
    int taskAmount;
	//dependencyAmount = 0;
    //char taskName[MAX_NAME_LENGTH];
    //int dependentTask[MAX_DEPENDENCIES];

    // initialise an array of type Task
    Task tasksArray[MAX_TASKS];


    printf("Welcome to the Gantt Generator\n");
    fflush(stdout);

    while (programActive) {
        printf("Would you like to use the test example or create your own Gantt from scratch? (Y/N/E(end))\n");
        fflush(stdout);
        scanf(" %c", &yesOrNo);

        if (yesOrNo == 'E' || yesOrNo == 'e')
        {
            printf("Program ended.\n");
            fflush(stdout);
            programActive = false;
        }
        else if (yesOrNo == 'Y' || yesOrNo == 'y')
        {
            printf("\n");
            showGantTemplate();
            printf("\n");
        }
        else if (yesOrNo == 'N' || yesOrNo == 'n')
        {
            printf("How many tasks would you like to add? (1-10)\n");
            fflush(stdout);
            scanf("%d", &taskAmount);

            for (int i = 0; i < taskAmount; i++) {
                populateTasks(&tasksArray[i]);
            }

            //int smallestMonth = tasksArray[0].startMonth;
            //int largestMonth = tasksArray[0].endMonth;

            // checking if output looks good

           /* for (int i = 0; i < taskAmount; i++) {
                // printf("Name: %s, \tStart Month: %4d, \tEnd Month: %4d\n",
                //     tasksArray[i].taskName,
                //     tasksArray[i].startMonth,
                //     tasksArray[i].endMonth);

                if (tasksArray[i].startMonth < smallestMonth) {
                    smallestMonth = tasksArray[i].startMonth;
                }

                if (tasksArray[i].endMonth > largestMonth) {
                    largestMonth = tasksArray[i].endMonth;
                }
            }*/

            // printf("Largest month: %d\n", largestMonth);
            // printf("Smallest month: %d\n", smallestMonth);


            displayGant(tasksArray, taskAmount);

            askEditInput(tasksArray, taskAmount);
            // breaks out of the while loop
            programActive = false;

        }
    }



}



void askEditInput(Task tasksArray[], int taskAmount) {

    char editOrTestOrQuit[MAX_NAME_LENGTH];

    printf("YOOOOO");
    fflush(stdout);
    do {

        printf("\nIf you wish to edit the Gantt please type 'edit'.\n");
        fflush(stdout);
        printf("If you wish to run a test, type 'test'\n");
        fflush(stdout);
        printf("If you wish to exit the program, type 'quit'\n");
        fflush(stdout);

        scanf(" %49s", editOrTestOrQuit);

        if (strcmp(editOrTestOrQuit, "edit") == 0) {
            editGant(tasksArray, taskAmount);
            displayGant(tasksArray, taskAmount);
        }
        else if (strcmp(editOrTestOrQuit, "test") == 0) {
            testDependencies();
        }

    } while (strcmp(editOrTestOrQuit, "quit") != 0);

    return; //at this point, user entered quit so returns back to main where there is nothing else to do

}
