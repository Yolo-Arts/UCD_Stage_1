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
