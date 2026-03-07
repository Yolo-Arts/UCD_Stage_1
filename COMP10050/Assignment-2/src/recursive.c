/*
 * input.c
 *
 *  Created on: 6 March 2026
 *      Author: Weng Kiat
 */

#include <stdio.h>
#include "input.h"
#include <stdbool.h>
#include <string.h>


void printDependentTasks(Task taskList[], int taskId, int visitedTasks[]);

int main(void) {
    Task project[MAX_TASKS];
    int totalTasks;

    // TEST CASE 1 (an example of a circual dependency) //
    // totalTasks = 5;
    // strcpy(project[0].taskName, "Logging");
    // project[0].dependencyAmount = 0;

    // strcpy(project[1].taskName, "Database");
    // project[1].dependencyAmount = 1;
    // project[1].dependentTasks[0] = 1;

    // strcpy(project[2].taskName, "Encryption");
    // project[2].dependencyAmount = 1;
    // project[2].dependentTasks[0] = 4;

    // // Circular Dependency
    // strcpy(project[3].taskName, "Auth");
    // project[3].dependencyAmount = 1;
    // project[3].dependentTasks[0] = 3;

    // // Task 4: App (Depends on Encryption)
    // strcpy(project[4].taskName, "App");
    // project[4].dependencyAmount = 1;
    // project[4].dependentTasks[0] = 3;

    // TEST CASE 2 (taken from week 7 lecture) //
    totalTasks = 10;
    strcpy(project[0].taskName, "Find_Bank");
    project[0].dependencyAmount = 0;


    strcpy(project[1].taskName, "Set_mortgage_approval");
    project[1].dependencyAmount = 1;
    project[1].dependentTasks[0] = 1;


    strcpy(project[2].taskName, "Draw_down");
    project[2].dependencyAmount = 2;
    project[2].dependentTasks[0] = 1;
    project[2].dependentTasks[1] = 2;


    strcpy(project[3].taskName, "Build_Foundation");
    project[3].dependencyAmount = 1;
    project[3].dependentTasks[0] = 3;


    strcpy(project[4].taskName, "Build_Walls");
    project[4].dependencyAmount = 0;

    strcpy(project[5].taskName, "Roof_and_ceiling");
    project[5].dependencyAmount = 2;
    project[5].dependentTasks[0] = 4;
    project[5].dependentTasks[1] = 5;

    strcpy(project[6].taskName, "Plumbing");
    project[6].dependencyAmount = 1;
    project[6].dependentTasks[0] = 6;

    strcpy(project[7].taskName, "Electrics");
    project[7].dependencyAmount = 1;
    project[7].dependentTasks[0] = 7;

    strcpy(project[8].taskName, "Inspect_Build");
    project[8].dependencyAmount = 1;
    project[8].dependentTasks[0] = 5;

    strcpy(project[9].taskName, "Snagging");
    project[9].dependencyAmount = 2;
    project[9].dependentTasks[0] = 8;
    project[9].dependentTasks[1] = 9;

    int visitedTasks[MAX_TASKS] = {0};
    printf("\n");
    printDependentTasks(project, totalTasks - 1, visitedTasks);
    printf("\n");

    return 0;
}


void printDependentTasks(Task taskList[], int taskId, int visitedTasks[]) {
    printf("%d -> ", taskId + 1);
    visitedTasks[taskId] = 1;

    for (int i = 0; i < taskList[taskId].dependencyAmount; i++) {
        int dependentTaskId = taskList[taskId].dependentTasks[i] - 1;

        if (visitedTasks[dependentTaskId] == 0) {
            printDependentTasks(taskList, dependentTaskId, visitedTasks);
        } else {
            printf("%d ( !!!!!!!! warning potential circular dependency !!!!!!!! )\n", dependentTaskId + 1);
            return;
        }
    }
}

// void printDependentTasks(Task taskList[], int taskId, int visitedTasks[]) {
//     printf("%d -> ", taskId + 1);
//     visitedTasks[taskId] = 1;

//     for (int i = 0; i < taskList[taskId].dependencyAmount; i++) {
//         int dependentTaskId = taskList[taskId].dependentTasks[i] - 1;

//         if (visitedTasks[dependentTaskId] == 0) {
//             printDependentTasks(taskList, dependentTaskId, visitedTasks);
//         } else {
//             printf("%d ( !!!!!!!! warning potential circular dependency !!!!!!!! )\n", dependentTaskId + 1);
//             checkIfCircular(taskList, dependentTaskId, resetVisitedTasks, dependentTaskId);
//             return;
//         }
//     }
// }


