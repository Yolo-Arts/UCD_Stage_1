#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_DEPENDENCIES 10
#define MAX_TASKS 10

typedef struct {
    char taskName[MAX_NAME_LENGTH];
    int dependencyAmount;
    int dependentTasks[MAX_DEPENDENCIES];
} Task;

int hasCycle(int index, Task tasks[], int visited[], int onStack[]) {
    if (onStack[index]) {
        return 1;
    }

    if (visited[index]) {
        return 0;
    }

    onStack[index] = 1;
    visited[index] = 1;

    for (int i = 0; i < tasks[index].dependencyAmount; i++) {
        int nextTaskIndex = tasks[index].dependentTasks[i];
        if (hasCycle(nextTaskIndex, tasks, visited, onStack)) {
            return 1;
        }
    }

    onStack[index] = 0;
    return 0;
}

int check_for_circular_dependencies(Task tasks[], int totalTasks) {
    int visited[MAX_TASKS];
    int onStack[MAX_TASKS];

    for (int i = 0; i < totalTasks; i++) {
        if (hasCycle(i, tasks, visited, onStack)) {
            printf("Error: Circular dependency detected involving task %s!\n", tasks[i].taskName);
            return 1;
        }
    }
    return 0;
}