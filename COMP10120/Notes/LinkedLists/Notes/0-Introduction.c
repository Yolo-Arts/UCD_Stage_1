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
    root.next->next = NULL;


    printf("First number is: %d\n", root.x);
    printf("Second number is: %d\n", root.next->x);

    free(root.next);

    return 0;
}