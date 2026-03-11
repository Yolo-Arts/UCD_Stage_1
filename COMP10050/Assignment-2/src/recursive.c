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
#include "recursive.h"


void printDependentTasks(Task taskList[], int taskId, int visitedTasks[]) {
    printf("%d -> ", taskId + 1);
    visitedTasks[taskId] = 1;

    for (int i = 0; i < taskList[taskId].dependencyAmount; i++) {
        int dependentTaskId = taskList[taskId].dependentTasks[i] - 1;

        if (visitedTasks[dependentTaskId] == 0) {
            printDependentTasks(taskList, dependentTaskId, visitedTasks);
        } else {
            printf("%d ( !!!!!!!! warning potential circular dependency !!!!!!!! )\n\n", dependentTaskId + 1);
            return;
        }
    }

    //visitedTasks[taskId] = 0;
}




