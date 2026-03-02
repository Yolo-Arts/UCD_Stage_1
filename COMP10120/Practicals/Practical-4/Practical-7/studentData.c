/*
Implement a C program that reads student records from a binary file (students.dat) and displays them on the screen.

Each student record consists of:

id (integer)
name (string, max 50 characters)
gpa (floating-point)
Your program must read from the binary file and print the student details in the format as per the test cases.

For example:

Result
ID: 1001, Name: Alice, GPA: 2.98
ID: 1002, Name: Bob, GPA: 3.56
ID: 1003, Name: Charlie, GPA: 3.65
ID: 1004, Name: David, GPA: 2.52
ID: 1005, Name: Emma, GPA: 2.33
ID: 1006, Name: Fiona, GPA: 2.97
ID: 1007, Name: George, GPA: 2.61
ID: 1008, Name: Hannah, GPA: 3.34
ID: 1009, Name: Isaac, GPA: 2.10
ID: 1010, Name: Jack, GPA: 3.97
ID: 1011, Name: Katherine, GPA: 2.54
ID: 1012, Name: Liam, GPA: 3.39
ID: 1013, Name: Mia, GPA: 3.68
ID: 1014, Name: Nathan, GPA: 2.66
ID: 1015, Name: Olivia, GPA: 3.21
ID: 1016, Name: Patrick, GPA: 2.86
ID: 1017, Name: Quinn, GPA: 3.91
ID: 1018, Name: Rachel, GPA: 3.87
ID: 1019, Name: Samuel, GPA: 3.56
ID: 1020, Name: Tina, GPA: 2.26
ID: 1021, Name: Umar, GPA: 3.09
ID: 1022, Name: Violet, GPA: 3.05
ID: 1023, Name: William, GPA: 3.41
ID: 1024, Name: Xavier, GPA: 2.24
ID: 1025, Name: Yasmine, GPA: 2.73
ID: 1026, Name: Zane, GPA: 4.00
ID: 1027, Name: Sophia, GPA: 3.22
ID: 1028, Name: Daniel, GPA: 3.20
ID: 1029, Name: Elena, GPA: 2.39
ID: 1030, Name: Frank, GPA: 3.98
ID: 1031, Name: Grace, GPA: 2.99
ID: 1032, Name: Henry, GPA: 3.61
ID: 1033, Name: Isabelle, GPA: 3.29
ID: 1034, Name: James, GPA: 3.22
ID: 1035, Name: Kelly, GPA: 3.43
ID: 1036, Name: Leo, GPA: 2.53
ID: 1037, Name: Monica, GPA: 2.75
ID: 1038, Name: Noah, GPA: 3.65
ID: 1039, Name: Oscar, GPA: 2.84
ID: 1040, Name: Penny, GPA: 3.22
ID: 1041, Name: Ronald, GPA: 3.80
ID: 1042, Name: Samantha, GPA: 3.11
ID: 1043, Name: Timothy, GPA: 2.37
ID: 1044, Name: Ursula, GPA: 3.82
ID: 1045, Name: Victor, GPA: 2.29
ID: 1046, Name: Wendy, GPA: 2.43
ID: 1047, Name: Xander, GPA: 2.29
ID: 1048, Name: Yvette, GPA: 3.05
ID: 1049, Name: Zachary, GPA: 3.67
ID: 1050, Name: Amber, GPA: 3.08
*/

// #include <stdio.h>

// int main(void) {

//     FILE *fp;

//     int id;
//     char name[50];
//     float gpa;

//     fp = fopen("students.dat", "r");

//     if (fp != NULL) {
//         while (fscanf(fp, "%d%s%f", &id, name, &gpa) == 3) {
//             printf("%5d %-50s %-10f\n",  id, name, gpa);

//         }
//         fclose(fp);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include<stdlib.h>

// #define MAX_NAME 50

// typedef struct {
//     int id;
//     char name[MAX_NAME];
//     float gpa;
// } Student;

// void read_from_binary (const char *binary_filename);

// int main(void) {
//     const char *binary_file = "students.dat";
//     read_from_binary()
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct stats {
    int id;
    char name[50];
    float gpa;
};
int main(){
    FILE *cfPtr;

    if((cfPtr = fopen("students.dat", "rb")) == NULL){
        printf("File could not be opened");
    } else {
        struct stats data;
        while(fread(&data, sizeof(struct stats), 1, cfPtr) == 1){

              printf("ID: %d, Name: %s, GPA: %.2f\n", data.id, data.name, data.gpa);

        }
        fclose(cfPtr);
    }
}