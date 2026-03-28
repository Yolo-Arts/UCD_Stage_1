#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // note the naming
    int x;
    struct Node* next; // note the initialisation due to typedef
} Node;

void insert_end(Node** root, int value);

void insert_beginning(Node** root, int value);

void insert_after(Node* root, int value);

void deallocate(Node** root);

int main(void) {
    Node* root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 3);
    insert_end(&root, 4);

    insert_after(root, 2);
    insert_after(root->next->next->next, 5);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d\n", curr->x);
    }

    // free(root.next);
    deallocate(&root);

    fflush(stdout);
    return 0;
}

void insert_end(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }

    new_node->next = NULL;
    new_node->x = value;

    // if array is empty
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

void insert_beginning(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(3);
    }

    new_node->x = value;
    new_node->next = *root;

    *root = new_node;
}

void insert_after(Node* root, int value) {
    Node* new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        exit(4);
    }

    new_node->x = value;
    new_node->next = root->next;
    root->next = new_node;
}

void deallocate(Node** root) {
    Node* curr = *root;
    while (curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux);
    }

    *root = NULL;
}