# Stuff to fix

1. Fix the horizontal line being hardcoded. Right now, the length of the line does not adjust depending on the amount of months.
    Run main.c and you will see.

2. Include dependencies in the Gantt. They are not being printed to the Gantt.

3. Refactor the code so that the code for displaying the Gantt is in a separate function.
    Right now everything is inside askInput() function which is messy.
    Doing this will make implementing task 3 easier.

    Feel free to put any other code in their own separate functions to make the code easier and/or make new header files to split the project up into different files (for example, display.c and display.h for displaying the Gantt).

4. Do task 2-3 where the user can edit the gantt chart (do not worry about circular dependencies)
    Loop through the "taskArray" array that holds the array of structs, to find the specific task to be edited.

    There is some existing code that you can reference on how to edit structs in input.c: populateTasks()

5. Use the .gitignore to ignore stuff unrelated to the project. We just want to keep .c and .h files in the project.
    I have already ignored .exe files.

# Stuff to fix 2
Code is in the src folder, recursive.c
1. It is right now using a main() as I independently tested the recursive function to check if it worked. Seems to have worked.
    You can check the test cases and see to see it working.
    Implement the recursive check with the gantt. (take it out of the hardcoded testing)
2. Check the week 7 slide. On the last few slides, the printDependentTasks looks like the below code:

    ```c
    void printDependentTasks(Task taskList[], int taskId, int visitedTasks[]) {
        printf("%d -> ", taskId + 1);
        visitedTasks[taskId] = 1;

        for (int i = 0; i < taskList[taskId].dependencyAmount; i++) {
            int dependentTaskId = taskList[taskId].dependentTasks[i] - 1;

            if (visitedTasks[dependentTaskId] == 0) {
                printDependentTasks(taskList, dependentTaskId, visitedTasks);
            } else {
                printf("%d ( !!!!!!!! warning potential circular dependency !!!!!!!! )\n", dependentTaskId + 1);
                checkIfCircular(taskList, dependentTaskId, resetVisitedTasks, dependentTaskId);
                return;
            }
        }
    }
    ```

    I have no clue what the checkIfCircular function even does. Currently, in the recursive.c, I have omitted this line of code (refer to commented and uncommented functions).