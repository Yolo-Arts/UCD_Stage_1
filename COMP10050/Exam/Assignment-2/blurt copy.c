#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_DEPENDENCIES 10
#define MAX_TASKS 10

typedef struct {
    char name[MAX_LENGTH];
    int dependencyAmount;
    int dependentTasks[MAX_DEPENDENCIES];
} Task;

int has_cycle(int index, Task tasks[], int visited[], int onStack[]) {
    if (onStack[index]) {
        return 1;
    }

    if (visited[index]) {
        return 0;
    }

    onStack[index] = 1;
    visited[index] = 1;

    for (int i = 0; i < tasks[index].dependencyAmount; i++) {
        int next_index = tasks[index].dependentTasks[i];
        if (has_cycle(next_index, tasks, visited, onStack)) {
            return 1;
        }
    }

    onStack[index] = 0;
    return 0;
}

int checkForCircularDependencies(Task tasks[], int taskAmount) {
    int onStack[MAX_TASKS];
    int visited[MAX_TASKS];

    for (int i = 0; i < taskAmount; i++) {
        if (has_cycle(i, tasks, onStack,visited)) {
            return 1;
        }
    }

    return 0;
}