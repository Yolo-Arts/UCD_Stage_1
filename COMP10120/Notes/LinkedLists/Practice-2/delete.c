#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insert_end(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Malloc failed!");
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
    while(curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

void delete_node(Node* target) {
    Node* curr = target;
    Node* next = target->next;
    Node* temp = next;
    temp->value = next->value;

    curr->value = next->value;
    next->value = temp->value;
    curr->next = next->next;
    free(next);
}


int main(void) {

    Node* root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 2);
    insert_end(&root, 3);
    insert_end(&root, 4);
    insert_end(&root, 5);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
    printf("\n");

    delete_node(root->next->next);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }

    dealloc(&root);

    return 0;
}
