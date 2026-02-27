#include <stdio.h>
#define MAX_STUDENTS 10

typedef struct {
    char name[100];
    int score;
    char grade;
} Student;

void getStudentGrade(Student *s) {
    printf("Enter student name: \n");
    scanf("%s", s->name);

    printf("Enter student score: \n");
    scanf("%d", &s->score);

    if (s->score >= 85) {
        s->grade = 'A';
    }
    else if (s-> score >= 70) {
        s->grade = 'B';
    }
    else if (s-> score >= 55) {
        s->grade = 'C';
    }
    else if (s-> score >= 40) {
        s->grade = 'D';
    }
    else if (s-> score >= 25) {
        s->grade = 'E';
    } else {
        s->grade = 'F';
    }
}

int main(void) {

    Student classroom[MAX_STUDENTS];

    int numStudents;
    printf("How many students are in the class?: \n");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("\n--- Student #%d ---\n", i);
        getStudentGrade(&classroom[i]);
    }

    printf("\nClassroom: \n");
    double sum = 0;
    for (int i = 0; i < numStudents; i++) {
        printf("\tStudent #%d, \tName: %20s, \tScore: %10d, Grade: %5c\n", i, classroom[i].name, classroom[i].score, classroom[i].grade);
        sum += classroom[i].score;
    }

    double average = sum / (double)numStudents;

    printf("Student average is: %.2lf", average);

    return 0;
}