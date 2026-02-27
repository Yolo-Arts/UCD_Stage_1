#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date enrollmentDate; // Nested struct!
    float gpa;
} Student;

int main() {
    // Initializing nested structs uses nested braces {{ }}
    Student s1 = {"Alice Murphy", {15, 9, 2023}, 3.9};

    printf("Student: %s\n", s1.name);

    // Accessing nested members using the dot operator twice
    printf("Enrolled on: %02d/%02d/%d\n",
            s1.enrollmentDate.day,
            s1.enrollmentDate.month,
            s1.enrollmentDate.year);

    return 0;
}