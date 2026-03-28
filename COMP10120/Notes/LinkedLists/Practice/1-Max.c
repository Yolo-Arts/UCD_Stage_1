#include <stdio.h>
#include <stdlib.h>

// Write a function int find_max(Node* root) that returns the highest integer in the list.

typedef struct Node {
    int num;
    struct Node* next;
} Node;

void insert_end(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Malloc failed!");
        exit(1);
    }

    new_node->num = value;
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

int find_max(Node* root) {
    
    if (root == NULL) {
        printf("List is empty.");
        return 0;
    }

    int max = root->num;
    
    Node* curr = root;
    while (curr != NULL) {
        if (curr->num > max) {
            max = curr->num;
        }
        curr = curr->next;
    }

    return max;
}

int main(void) {
    Node* root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 2);
    insert_end(&root, 3);
    insert_end(&root, 4);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->num);
    }

    int max = find_max(root);
    printf("Max is %d", max);

    deallocate(&root);

    return 0;
}