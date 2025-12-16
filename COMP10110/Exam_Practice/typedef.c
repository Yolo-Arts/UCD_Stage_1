#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
}Student;

int main() {

    Student student1 = {"Jack", 19, 3.6, true};

    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("GPA: %.02f\n", student1.gpa);
    printf("IsFullTime?: %s\n", (student1.isFullTime > 0) ? "Yes" : "No");

    return 0;
}