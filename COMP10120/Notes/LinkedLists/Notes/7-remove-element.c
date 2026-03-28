#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // note the naming
    int x;
    struct Node* next; // note the initialisation due to typedef
} Node;

void insert_end(Node** root, int value);

void insert_beginning(Node** root, int value);

void insert_after(Node* root, int value);

void insert_sorted(Node** root, int value);

void remove_element(Node** root, int value);

void deallocate(Node** root);

int main(void) {
    Node* root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 3);
    insert_end(&root, 4);
    remove_element(&root, 1);
    remove_element(&root, 4);


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

void insert_sorted(Node** root, int value) {
    if (*root == NULL || (**root).x >= value) {
        insert_beginning(root, value);
        return;
    }

    Node* curr = *root;
    while (curr->next != NULL) {
        if (curr->next->x >= value) {
            insert_after(curr, value);
            return;
        }
        curr = curr->next;
    }

    insert_after(curr, value);
    // insert_end(root, value); // I think this might work as well as its the last element.
}

void remove_element(Node** root, int value) {
    if (*root == NULL) {
        return;
    }

    if ((**root).x == value) { // if first element is the one item to remove.
        Node* to_remove = *root;
        *root = (**root).next;
        free(to_remove);
        return;
    }

    Node* curr = *root;
    while(curr->next != NULL) {

        if (curr->next->x == value) {
            // free(curr->next);
            Node* to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
            return;
        }

        curr = curr->next;
    }
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
