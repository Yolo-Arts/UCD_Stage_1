#include <stdio.h>
#include <stdlib.h>

// this program counts the number of occurences in a linked list.

typedef struct Node{
    int value;
    struct Node* next;
} Node;

void insert_end(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Malloc failed");
        exit(1);
    }

    new_node->value = value;
    new_node->next = NULL;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    Node* curr = *root;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
}

void dealloc(Node** root) {
    Node* curr = *root;
    while (curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

int count_occurrences(Node* root, int target) {
    Node* curr = root;
    int counter = 0;

    while (curr != NULL) {
        if (curr->value == target) {
            counter++;
        }
        curr = curr->next;
    }

    return counter;
}

int main (void) {

    Node* root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 2);
    insert_end(&root, 2);
    insert_end(&root, 2);
    insert_end(&root, 3);


    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
    printf("\n");

    int value_to_find = 2;
    int result = count_occurrences(root, value_to_find);
    printf("The amount that %d occurs in the list is %d\n", value_to_find, result);

    dealloc(&root);

    return 0;
}