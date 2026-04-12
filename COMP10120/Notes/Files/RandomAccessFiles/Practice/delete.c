#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_num;
    double balance;
} account;

void deleteRecord(char* filename) {
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    int account_to_delete;
    account blankAccount = {0, 0.0}; // The "Eraser"

    printf("Enter account number to delete (1-100): ");
    scanf("%d", &account_to_delete);

    // 1. Move the cursor to the start of that record
    // Offset formula: (ID - 1) * size
    fseek(fp, (account_to_delete - 1) * sizeof(account), SEEK_SET);

    // 2. Overwrite whatever was there with our blank struct
    fwrite(&blankAccount, sizeof(account), 1, fp);

    printf("Account #%d has been deleted (zeroed out).\n", account_to_delete);

    fclose(fp);
}

