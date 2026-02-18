#include <stdio.h>

// struct employee {
//     char firstName[100];
//     char lastName[100];
//     int age;
// }; // REMMEBER THE SEMI COLON AT THE END OF THE STRUCT

// struct decleration:
// struct employee alice, bob;

struct employee {
    char firstName[100];
    char lastName[100];
    int age;
}; 

// The use of typedef when defining a struct
// allows us to declare variables alice, bob without using 'struct'
// employee alice, bob;


int main(void) {
    struct employee alice = {"alice", "murphy", 19};
    printf("Full name is %s %s\n", alice.firstName, alice.lastName);
    printf("Age: %d\n", alice.age);

    return 0;
}