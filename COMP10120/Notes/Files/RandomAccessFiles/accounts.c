#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int accNum;
    char lastName[15];
    char firstName[10];
    double balance;
} clientData;

void initializeFile(const char *filename);
void writeToRandomFile(const char *filename);
void readSequentially(const char *filename);

int main(void) {
    const char *filename = "accounts.dat";
    // initializeFile(filename);

    writeToRandomFile(filename);

    readSequentially(filename);

    return 0;
}

// Creates a file with 100 blank structs
void initializeFile(const char *filename) {
    FILE *cfPtr = fopen(filename, "wb+");
    if (cfPtr == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    clientData blankClient = {0, "", "", 0.0};
    for (unsigned int i = 1; i <= 100; i++) {
        fwrite(&blankClient, sizeof(clientData), 1, cfPtr);
    }
    fclose(cfPtr);
    printf("File initialized with 100 blank records.\n");
}

void writeToRandomFile(const char *filename) {
    FILE *cfPtr = fopen(filename, "rb+");
    if (cfPtr == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    clientData client = {0, "", "", 0.0};
    printf("\nEnter account number (1-100, 0 to end): ");
    scanf("%u", &client.accNum);

    while (client.accNum != 0) {
        printf("Enter lastname, firstname, balance: ");
        scanf("%14s %9s %lf", client.lastName, client.firstName, &client.balance);

        // (accNum - 1) because account 1 is at byte 0
        fseek(cfPtr, (client.accNum - 1) * sizeof(clientData), SEEK_SET);

        fwrite(&client, sizeof(clientData), 1, cfPtr);

        printf("Enter account number: ");
        scanf("%u", &client.accNum);
    }
    fclose(cfPtr);
}

void readSequentially(const char *filename) {
    FILE *cfPtr = fopen(filename, "rb");
    if (cfPtr == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    printf("\n%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");

    clientData client = {0, "", "", 0.0};
    while (fread(&client, sizeof(clientData), 1, cfPtr) == 1) {
        if (client.accNum != 0) {
            printf("%-6u%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName, client.balance);
        }
    }
    fclose(cfPtr);
}