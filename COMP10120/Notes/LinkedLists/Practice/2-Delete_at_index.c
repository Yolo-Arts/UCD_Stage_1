#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int x;
    struct Node* next;
} Node;

// write a program that deletes a linked list at index x.

void insert_end(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        exit(1);
    }

    new_node->x = value;
    new_node->next = NULL;

    if (*root == NULL) {
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
}

void deallocate(Node** root) {
    Node* curr = *root;
    while(curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

void delete_at_index(Node** root, int index) {
    if (*root == NULL) {
        printf("Nothing to delete: List is empty");
        return;
    }
    int counter = 0;

    Node* prev = NULL;
    Node* curr = *root;

    if (index == 0) {
        *root = curr->next;
        free(curr);
        return;
    }

    while(curr != NULL) {
        if (counter == index) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
        counter++;
    }

    printf("Outside range of list!\n");
}

int main(void) {
    Node* root = NULL;
    insert_end(&root, 1);
    insert_end(&root, 2);
    insert_end(&root, 3);
    insert_end(&root, 4);
    insert_end(&root, 5);

    delete_at_index(&root, 4);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->x);
    }

    deallocate(&root);

    return 0;
}