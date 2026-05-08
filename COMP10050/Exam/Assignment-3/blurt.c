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

void insert_end(List **startPtr, char *value);
void insert_end_item(Item **startPtr, char *value);

void readFile(List **startPtr, char fileName[]) {
    FILE *fp;
    fp = fopen(fileName, "r");

    if (fp == NULL) {
        return;
    }

    *startPtr = NULL;
    char value[MAX_LENGTH];
    List *lastPtr = NULL;

    while (fgets(value, sizeof(value), fp)) {
        value[strcspn(value, "\r\n")] = 0;

        if (strlen(value) == 0) continue;

        if (strchr(value, ":")) {
            insert_end(startPtr, value);

            lastPtr = *startPtr;
            while(lastPtr->next != NULL) {
                lastPtr = lastPtr->next;
            }
        }
        else if (lastPtr != NULL) {
            insert_end_item(&(lastPtr->itemPtr), value);
        }
    }

    fclose(fp);
}