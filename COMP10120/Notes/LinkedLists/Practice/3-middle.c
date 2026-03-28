#include <stdio.h>
#include <stdlib.h>

// Write a program that finds the index at the middle of the linked list, without counting.
// Use two pointers, a fast and slow pointer.
// When fast pointer reaches the end, the position of the slow pointer is the middle index.
// Assume that the linked list is sorted.

typedef struct Node {
    int x;
    struct Node* next;
} Node;

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

void dealloc(Node** root) {
    Node* curr = *root;
    while(curr != NULL) {
        Node* aux = curr;
        curr = curr->next;
        free(aux);
    }
    *root = NULL;
}

int get_middle(Node* root) {
    Node* fast = root;
    Node* slow = root;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->x;
}


int main(void) {
    Node* root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 2);
    insert_end(&root, 3);
    insert_end(&root, 4);
    insert_end(&root, 5);
    // insert_end(&root, 6);
    // insert_end(&root, 7);

    for (Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->x);
    }

    int result = get_middle(root);
    printf("\nThe value at the middle of the linked list is: %d", result);

    dealloc(&root);

    return 0;
}