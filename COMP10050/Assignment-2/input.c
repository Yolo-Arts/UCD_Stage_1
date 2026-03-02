/*
 * input.c
 *
 *  Created on: 19 Feb 2026
 *      Author: Weng Kiat
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"
#include "testGantt.h"

// struct that will hold the data of each task.
typedef struct {
    char taskName[MAX_NAME_LENGTH];
    int startMonth;
    int endMonth;
    int depencyAmount;

    // array of dependent tasks
    int dependentTasks[MAX_DEPENDENCIES];
} Task;

void populateTasks(Task *t) {
    printf("Please enter the task name\n");
    scanf("%s", t->taskName);

    printf("Start Month (1-12):\n");
    scanf("%d", &t->startMonth);

    printf("End Month (1-12):\n");
    scanf("%d", &t->endMonth);

    printf("Enter how many dependencies this task has:\n");
    scanf("%d", &t->depencyAmount);

    for (int i = 0; i < t->depencyAmount; i++) {
        printf("Enter dependent task:\n");
        scanf("%d", &t->dependentTasks[i]);
    }
}

void askInput() {
    // bool createGanttFromScratch = false;

    // flag to ensure program runs until stopped.
    bool programActive = true;

    char yesOrNo;

    // int taskAmount, startMonth, endMonth, dependencyAmount = 0;
    int taskAmount, dependencyAmount = 0;
    char taskName[MAX_NAME_LENGTH];
    int dependentTask[MAX_DEPENDENCIES];

    // initialise an array of type Task
    Task tasksArray[MAX_TASKS];


    printf("Welcome to the Gantt Generator\n");

    while (programActive) {
        printf("Would you like to use the test example or create your own Gantt from scratch? (Y/N/E(end))\n");
        scanf(" %c", &yesOrNo);

        if (yesOrNo == 'E' || yesOrNo == 'e')
        {
            printf("Program ended.\n");
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
            scanf("%d", &taskAmount);

            for (int i = 0; i < taskAmount; i++) {
                populateTasks(&tasksArray[i]);
            }

            int smallestMonth = tasksArray[0].startMonth;
            int largestMonth = tasksArray[0].endMonth;

            // checking if output looks good

            for (int i = 0; i < taskAmount; i++) {
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
            }

            // printf("Largest month: %d\n", largestMonth);
            // printf("Smallest month: %d\n", smallestMonth);

            // this displays the months
            printf("\t\t\t|");

            for(int i = smallestMonth ; i <= largestMonth; i++){

                switch(i){
                case(0) :
                        printf("\t\t\t|");
                        break;
                case(january):
                        printf("  January   |");
                        break;
                case(february):
                        printf("  February  |");
                        break;
                case(march):
                        printf("   March    |");
                        break;
                case(april):
                        printf("   April    |");
                        break;
                case(may):
                        printf("    May     |");
                        break;
                case(june):
                        printf("    June    |");
                        break;
                case(july):
                        printf("    July    |");
                        break;
                case(august):
                        printf("   August   |");
                        break;
                case(september):
                        printf(" September  |");
                        break;
                case(october):
                        printf("  October   |");
                        break;
                case(november):
                        printf(" November   |");
                        break;
                case(december):
                        printf(" December   |");
                        break;
                // case(december + 1):
                //         printf(" Dependencies   \n");
                //         break;

                default:
                    break;

                }

            }

            printf(" Dependencies   |\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

            // prints out the customised Gantt:

            for (int i = 0; i < taskAmount; i++) {
                printf("%-24s|", tasksArray[i].taskName);
                for (int j = smallestMonth; j <= largestMonth; j++) {

                    if ((tasksArray[i].startMonth <= j) && (tasksArray[i].endMonth >= j)) {
                        printf("    xxx     |");
                    } else {
                        printf("            |");
                    }
                }
                printf("                |\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            }

            // displaying user generated Gantt Chart (deprecated):

            // printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            // printf("Internship Applications\t|            |    xxx     |    xxx     |    xxx     |            |            |            |            |            |            |            |            | 1   \n");
            // for (int i = 0; i < taskAmount; i++) {
            //     printf("%-25s| \tStart Month: %4d, \tEnd Month: %4d\n",
            //         tasksArray[i].taskName,
            //         tasksArray[i].startMonth,
            //         tasksArray[i].endMonth);
            // }


            // printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


            // breaks out of the while loop
            programActive = false;

        }
    }

    printf("If you wish to edit the Gantt please type 'edit'.\n");
    printf("If you wish to run a test, type 'test'\n");
    printf("If you wish to exit the program, type 'quit' and then press enter to execute your option");
}

void askEditInput() {

}