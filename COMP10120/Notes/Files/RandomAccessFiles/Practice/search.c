#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_num;
    double balance;
} account;

void searchFile(char* filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        exit(1);
    }

    int account_to_find;
    account client;
    printf("Enter the account number: ");
    scanf("%d", &account_to_find);

    fseek(fp, (account_to_find - 1) * sizeof(account), SEEK_SET);

    fread(&client, sizeof(account), 1, fp);

    if (client.account_num == 0) {
        printf("Client does not exist!");
    } else {
        printf("Account number: %d Balance: %lf\n", client.account_num, client.balance);
    }

    fclose(fp);
}