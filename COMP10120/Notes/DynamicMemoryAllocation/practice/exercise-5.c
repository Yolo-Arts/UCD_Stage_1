// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     char *name;
//     int age;
// } Student;

// int main(void) {
//     int age;
//     char *name;
//     int len;

//     Student student1;

//     printf("How long is your name?: ");
//     scanf("%d", &len);

//     student1.name = (char *)malloc((len + 1) * sizeof(char));
//     for (int i = 0; i < len; i++) {
//         scanf('%c ', name);
//     }

//     printf("The students name is : %s", student1.name);

//     free(student1.name);
//     free(student1)


//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} Student;

int main(void) {
    int len;
    
    Student *s1 = (Student *)malloc(sizeof(Student));
    if (s1 == NULL) return 1;

    printf("How long is your name?: ");
    scanf("%d", &len);

    s1->name = (char *)malloc((len + 1) * sizeof(char));
    if (s1->name == NULL) {
        free(s1); 
        return 1;
    }

    printf("Enter name: ");
    scanf("%s", s1->name);

    printf("Enter age: ");
    scanf("%d", &s1->age);

    printf("\nStudent: %s, Age: %d\n", s1->name, s1->age);

    free(s1->name); 
    free(s1);       

    return 0;
}