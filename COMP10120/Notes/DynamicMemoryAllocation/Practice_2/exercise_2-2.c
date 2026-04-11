#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int grade;
} Student;

int main(void) {

    int num_students = 0;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    Student *classroom = (Student *)malloc(num_students * sizeof(Student));

    for (int i = 0; i < num_students; i++) {
        printf("Enter student %d grade: ", i);
        scanf("%d", &classroom[i].grade);
    }

    float average = 0;

    for (int i = 0; i < num_students; i++) {
        printf("Student %d grade: %d\n", i, classroom[i].grade);
        average += classroom[i].grade;
    }

    printf("The class average is: %.2f", average / num_students);

    free(classroom);

    return 0;
}