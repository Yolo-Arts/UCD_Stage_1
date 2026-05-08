#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50

typedef struct Item {
    char name[MAX_LENGTH];
    struct Item* next;
} Item;

typedef struct List {
    char name[MAX_LENGTH];
    Item* itemPtr;
    struct List *next;
} List;

void edit_item_name(List *root) {
    Item *curr = root->itemPtr;

    char item_name_to_find[MAX_LENGTH];
    fgets(item_name_to_find, MAX_LENGTH, stdin);

    while (curr != NULL) {
        if (strcmp(item_name_to_find, curr->name) == 0) {
            char name_change[MAX_LENGTH];
            printf("Enter new item name:\n");
            fgets(name_change, MAX_LENGTH, stdin);

            strcpy(curr->name, name_change);
            return;
        }


        curr = curr->next;
    }
}