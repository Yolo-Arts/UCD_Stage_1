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
    struct List* next;
} List;

void read_file(List **startPtr, char fileName[]) {
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        return;
    }

    *startPtr = NULL;
    List *last_list = NULL;
    char value[MAX_LENGTH];

    while (fgets(value, sizeof(value), fp)) {
        value[strcspn(value, "\r\n")] = 0;

        if (strlen(value) == 0) continue;

        if (strchr(value, ":")) {
            insert_end(startPtr, value);

            last_list = *startPtr;
            while(last_list->next != NULL) {
                last_list = last_list->next;
            }
        }
        else if (last_list == NULL) {
            insert_end_item(&(last_list->itemPtr), value);
        }
    }

    fclose(fp);
}