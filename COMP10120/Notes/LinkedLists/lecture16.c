#include <stdio.h>
#include <stdlib.h>

// this program inserts and deletes nodes in a list

struct listNode{
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void) {
    ListNodePtr startPtr = NULL; // initially there are no nodes
    char item;

    instructions();
    printf("%s", "? ");
    unsigned int choice;
    scanf("%u", &choice);

    while (choice != 3) {
        switch (choice)
        {
        case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item);
            printList(startPtr);
            break;
        case 2:
            if (!isEmpty(startPtr)) {
                printf("Enter character to be deleted: ");
                scanf("\n%c", &item);

                if (delete(&startPtr, item)) {
                    printf("%c deleted.\n", item);
                    printLIst(startPtr);
                } else {
                    printf("%c not found.\n\n", item);
                }
            } else {
                puts("List is empty.\n");
            }

            break;
        default:
            puts("Invalid Choice.");
            instructions();
            break;
        }

        printf("? ");
        scanf("%u", &choice);
    }
    puts("End of run.");
}

void instructions(void) {
    puts("Enter your choice:\n"
        "\t 1 to insert an element into the list.\n"
        "\t 2 to delete an element from the list.\n"
        "\t 3 to end.");
}

void insert(ListNodePtr *sPtr, char value) {
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if (newPtr == NULL) {
        printf("%c not inserted. No memory available.\n");
    } else {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        while (currentPtr != NULL && value > currentPtr->data) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
}

char delete(ListNodePtr *sPtr, char value) {
    if (value == (*sPtr)->data) {
        ListNodePtr tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    } else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    
    return '\0';
}

int isEmpty(ListNodePtr sPtr) {
    return sPtr == NULL;
}

void printList(ListNodePtr currentPtr) {
    if (isEmpty(currentPtr)) {
        puts("List is empty.\n");
    } else {
        puts("THe list is: ");

        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}