#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // note the naming
    int x;
    struct Node* next; // note the initialisation due to typedef
} Node;

int main(void) {

    Node root;
    root.x = 5;
    root.next = malloc(sizeof(Node));
    root.next->x = 495;
    root.next->next = malloc(sizeof(Node));
    root.next->next->x = 15;
    root.next->next->next = NULL;


    // Using a while loop
    // Node* curr = &root;
    // while (curr != NULL) {
    //     printf("%d\n", curr->x);
    //     // curr = (*curr).next;
    //     curr = curr->next;
    // }

    // Iteration with for loop

    for (Node* curr = &root; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->x);
    }

    free(root.next);
    fflush(stdout);
    return 0;
}