#include <stdio.h>
#include <string.h>

// Using typedef means we don't have to type 'struct' every time
typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

// Function to print student info (Pass by value)
void displayStudent(Student s) {
    printf("Student: %s | ID: %d | GPA: %.2f\n", s.name, s.id, s.gpa);
}

// Function to update GPA (Pass by pointer)
// We use the arrow operator (->) to access members via a pointer
void updateGPA(Student *s, float newGPA) {
    if (newGPA >= 0.0 && newGPA <= 4.0) {
        s->gpa = newGPA;
    }
}

int main() {
    // 1. Array of structs
    Student classroom[3] = {
        {"Alice Murphy", 101, 3.8},
        {"Bob Murphy", 102, 3.2},
        {"Charlie Kelly", 103, 2.5}
    };

    printf("--- Original Records ---\n");
    for(int i = 0; i < 3; i++) {
        displayStudent(classroom[i]);
    }

    // 2. Modifying a record using a pointer
    printf("\nUpdating Charlie's GPA...\n");
    updateGPA(&classroom[2], 3.9);

    // 3. Showing the result
    displayStudent(classroom[2]);

    return 0;
}