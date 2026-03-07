/*
 * input.h
 *
 *  Created on: 19 Feb 2026
 *      Author: Weng Kiat
 */

/*
 * input.h
 *
 *  Created on: 5 Mar 2026
 *      Author: annie
 */

#ifndef INPUT_H_
#define INPUT_H_

#define MAX_NAME_LENGTH 100
#define MAX_DEPENDENCIES 10
#define MAX_TASKS 10

// struct that will hold the data of each task.
typedef struct {
    char taskName[MAX_NAME_LENGTH];
    int startMonth;
    int endMonth;
    int dependencyAmount;

    // array of dependent tasks
    int dependentTasks[MAX_DEPENDENCIES];
} Task;

void askInput();

void askEditInput(Task tasksArray[], int taskAmount);


#endif /* INPUT_H_ */
