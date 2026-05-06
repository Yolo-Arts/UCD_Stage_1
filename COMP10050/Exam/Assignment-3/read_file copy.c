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


void load_file(List **startPtr, char file_name[])
{
    FILE *fptr = fopen(file_name, "r");
    if (fptr == NULL) {
        printf("Error: Could not open %s\n", file_name);
        return;
    }

    *startPtr = NULL;

    char value[MAX_LEN];
    List *last_list = NULL;

    while (fgets(value, sizeof(value), fptr)) {
        value[strcspn(value, "\r\n")] = 0;

        if (strlen(value) == 0) continue;

        if (strchr(value, ':')) {
            insert_end(startPtr, value); // helper function that inserts List nodes to the end.

            last_list = *startPtr;
            while (last_list->next != NULL) {
                last_list = last_list->next;
            }
        }
        else if (last_list != NULL) {
            insert_end_item(&(last_list->itemsPtr), value); // helper function that inserts Item nodes to the end.
        }
    }

    fclose(fptr);
    printf("Successfully loaded board from %s\n", file_name);
}
