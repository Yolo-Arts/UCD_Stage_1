#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int grade;
    char name[20];
} Student;

void readFile(char* filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("File cannot be opened!");
        exit(1);
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, fp) == 1) {
        if (student.grade != 0) {
            printf("%d %s\n", student.grade, student.name);
        }
    }

    fclose(fp);
}

int main(void) {

    FILE *fp;

    fp = fopen("students.dat", "wb+");

    if (fp == NULL) {
        printf("File cannot be opened!");
        exit(1);
    }

    Student classroom = {0, ""};
    for (int i = 0; i < 20; i++) {
        fwrite(&classroom, sizeof(Student), 1, fp);
    }

    Student example = {95, "Alice"};
    fseek(fp, 4 * sizeof(Student), SEEK_SET); // Jump to 5th slot
    fwrite(&example, sizeof(Student), 1, fp);

    fclose(fp);

    readFile("students.dat");

    return 0;
}

