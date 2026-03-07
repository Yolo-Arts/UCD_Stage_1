/*
 * edit.c
 *
 *  Created on: 5 Mar 2026
 *      Author: annie
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

void editGant(Task tasksArray[], int taskAmount) {
	char taskToEdit[MAX_NAME_LENGTH];

	printf("Please enter the task name you wish to change exactly\n");
	fflush(stdout);
	scanf("%49s", taskToEdit);


	for (int i = 0; i < taskAmount; i++) {

		if(strcmp(tasksArray[i].taskName, taskToEdit) == 0){
			memset(&tasksArray[i], 0, sizeof(tasksArray[i])); //resets the values of the Task

		    printf("Please enter the new task name or write its old one:\n");
		    fflush(stdout);
		    scanf("%49s", tasksArray[i].taskName); //ensures will only read max 49 characters to allow for null character and avoid overflow

		    printf("Start Month (1-12):\n");
		    fflush(stdout);
		    scanf("%d", &tasksArray[i].startMonth);

		    printf("End Month (1-12):\n");
		    fflush(stdout);
		    scanf("%d", &tasksArray[i].endMonth);

		    printf("Enter how many dependencies this task has:\n");
		    fflush(stdout);
		    scanf("%d", &tasksArray[i].dependencyAmount);

		    for (int j = 0; j < tasksArray[i].dependencyAmount; j++) {
		        printf("Enter dependent task:\n");
		        fflush(stdout);
		        scanf("%d", &tasksArray[i].dependentTasks[j]);
		    }

		    break;
		}
	 }



}
