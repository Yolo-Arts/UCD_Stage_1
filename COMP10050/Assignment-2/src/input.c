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
#include "recursive.h"
#include "display.h"
#include "clear.h"



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


    // flag to ensure program runs until stopped.
    bool programActive = true;

    char yesOrNo;


    int taskAmount;


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
            taskAmount = loadTestExample(tasksArray);
            displayGant(tasksArray, taskAmount);
            printf("\n");
            askEditInput(tasksArray, taskAmount);
            programActive = false;
        }
        else if (yesOrNo == 'N' || yesOrNo == 'n')
        {
            printf("How many tasks would you like to add? (1-10)\n");
            fflush(stdout);
            scanf("%d", &taskAmount);

            for (int i = 0; i < taskAmount; i++) {
                populateTasks(&tasksArray[i]);
            }

            clearDisplay(); //clear screen before print gantt
            displayGant(tasksArray, taskAmount);

            askEditInput(tasksArray, taskAmount);
            // breaks out of the while loop
            programActive = false;

        }
    }



}



void askEditInput(Task tasksArray[], int taskAmount) {

    char editOrTestOrQuit[MAX_NAME_LENGTH];


    do {

        printf("If you wish to edit the Gantt please type 'edit'.\n");
        fflush(stdout);
        printf("If you wish to run a test, type 'test'\n");
        fflush(stdout);
        printf("If you wish to exit the program, type 'quit'\n");
        fflush(stdout);

        scanf("%49s", editOrTestOrQuit);

        if (strcmp(editOrTestOrQuit, "edit") == 0) {
            editGant(tasksArray, taskAmount);
            clearDisplay();   //clears screen before print new gantt
            displayGant(tasksArray, taskAmount);
        }
        else if (strcmp(editOrTestOrQuit, "test") == 0) {

        	int visitedTasks[MAX_TASKS] = {0};
        	int taskId = -1;
        	char testTaskName[MAX_NAME_LENGTH];

        	printf("\nPlease enter the task name to test\n");
        	fflush(stdout);
        	scanf("%s", testTaskName);

        	for (int i = 0; i < taskAmount; i++) {

        		if(strcmp(tasksArray[i].taskName, testTaskName) == 0){
        			taskId = i; //gives the index of the task youre testing
        			break; //stop looking when found
        		}
        	}

        	if (taskId == -1) {
        	    printf("Task not found.\n"); // just in case the task they enter is an invalid i.e not found so id never changed from -1
        	} else {
        	    printDependentTasks(tasksArray, taskId, visitedTasks);
        	}

        }

    } while (strcmp(editOrTestOrQuit, "quit") != 0);

    printf("\n");
    printf("ascii art:\n");
    printf(" /\\__/\\\n( . 3 .)\n/ u  u\\\n"); //need to use \\ to print a single back slash cause its a special chracter

    // the ASCII art of a masterfully created stickman.
    printf("\nASCII Art!\n");
    printf("  O  \n");
    printf(" /|V  \n");
    printf(" /\\  \n");
    printf("\nleg is a lil off center...\n");


    return; //at this point, user entered quit so returns back to main where there is nothing else to do

}
