#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

typedef struct Item {
    char name[MAX_LEN];
    struct Item* next;
} Item;

typedef struct List {
    char name[MAX_LEN];
    Item* itemsPtr;
    struct List* next;
} List;

void edit_item_name(List *root) {
    Item *curr = root->itemsPtr;

    char item_to_find[MAX_LEN];
    fgets(item_to_find, MAX_LEN, stdin);


    while (curr != NULL) {
        if (strcmp(curr->name, item_to_find) == 0) {
            char new_name[MAX_LEN];
            fgets(new_name, MAX_LEN, stdin);

            strcpy(curr->name, new_name);
            return;
        }

        curr = curr->next;
    }
}