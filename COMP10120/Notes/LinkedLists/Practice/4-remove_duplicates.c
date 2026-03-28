#include <stdio.h>
#include <stdlib.h>

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
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
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

void remove_duplicates(Node* root) {
    if (root == NULL || root->next == NULL) {
        return;
    }
    Node* curr = root->next;
    Node* prev = root;

    while (curr != NULL) {
        if (prev->x == curr->x) {
            printf("Prev is the same as Curr ");
            if (curr->next == NULL) {
                printf("\nReached last element\n");
                prev->next = NULL;
                free(curr);
                return;
            }

            while (curr->x == curr->next->x) {
                Node* aux = curr;
                curr = curr->next;
                free(aux);
            }

            curr = curr->next;
            prev->next = curr;
        }
        prev = curr;
        curr = curr->next;
        printf("Prev: %d, Curr: %d\n", prev->x, curr->x);
    }
}

/* ALTERNATIVE SOLUTIONS:
void remove_duplicates_two_pointer(Node* root) {
    if (root == NULL || root->next == NULL) return;

    Node* prev = root;
    Node* curr = root->next;

    while (curr != NULL) {
        if (prev->x == curr->x) {
            // Found a duplicate!
            prev->next = curr->next; // Bypass curr
            free(curr);              // Delete curr
            curr = prev->next;       // Bring the NEW neighbor into curr
            // Note: We do NOT move prev here. We need to check it against the new curr.
        } else {
            // No match? Move BOTH forward.
            prev = curr;
            curr = curr->next;
        }
    }
}

void remove_duplicates_look_ahead(Node* root) {
    Node* curr = root;

    // while current node and next node exist
    while (curr != NULL && curr->next != NULL) {
        if (curr->x == curr->next->x) {
            // Twins! Delete the second one.
            Node* temp = curr->next;
            curr->next = curr->next->next; // Stitch curr to the node after temp
            free(temp);
            // DO NOT move curr forward. 
            // The new curr->next might also be a duplicate!
        } else {
            // Safe to move forward
            curr = curr->next;
        }
    }
}

*/


int main(void) {
    Node* root = NULL;
    printf("Original List: \n");
    insert_end(&root, 1);
    insert_end(&root, 2);
    insert_end(&root, 2);
    insert_end(&root, 2);
    insert_end(&root, 3);
    insert_end(&root, 3);
    insert_end(&root, 4);
    insert_end(&root, 5);
    insert_end(&root, 5);

    for(Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->x);
    }

    remove_duplicates(root);
    printf("\nRemoved Duplicates List: \n");

    for(Node* curr = root; curr != NULL; curr = curr->next) {
        printf("%d ", curr->x);
    }

    deallocate(&root);

    return 0;
}