#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_num;
    double balance;
} account;

// void updateFile(char* filename) {
//     FILE *fp = fopen(filename, "rb+");
//     if (fp == NULL) {
//         exit(1);
//     }

//     account user;
//     printf("Enter account number (-1 to exit): ");
//     scanf("%d", &user.account_num);

//     while (user.account_num != -1) {
//         printf("Enter balance: ");
//         scanf("%d", &user.balance);

//         fseek(fp, (user.account_num - 1) * sizeof(account), SEEK_SET);

//         fwrite(&user, sizeof(account), 1, fp);

//         printf("Enter account number (-1 to exit): ");
//         scanf("%d", &user.account_num);
//     }

//     // while(user.balance != 0) {
//     //     printf("%d Balance: %d\n", user.account_num, user.balance);
//     // }

//     fclose(fp);
// }

void updateFile(char* filename) {
    FILE *fp = fopen(filename, "rb+"); // Always use the parameter filename
    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }

    int account_to_find;
    double transaction;
    account user;

    printf("Enter account number to update (1-100, -1 to exit): ");
    scanf("%d", &account_to_find);

    while (account_to_find != -1) {
        // 1. SEEK to the record
        fseek(fp, (account_to_find - 1) * sizeof(account), SEEK_SET);

        // 2. READ the current data into memory
        fread(&user, sizeof(account), 1, fp);

        if (user.account_num == 0) {
            printf("Account #%d does not exist.\n", account_to_find);
        } else {
            printf("Current balance: %.2f. Enter transaction amount (+ for deposit, - for withdrawal): ", user.balance);
            scanf("%lf", &transaction); // FIXED: Use %lf for double

            // 3. MODIFY the data in memory
            user.balance += transaction;

            // 4. SEEK BACK to the same spot
            // Important: fread moved the file pointer to the START of the NEXT record.
            // We must move it back to the start of the CURRENT record.
            fseek(fp, (account_to_find - 1) * sizeof(account), SEEK_SET);

            // 5. WRITE the updated struct back to the file
            fwrite(&user, sizeof(account), 1, fp);
            printf("New balance: %.2f\n", user.balance);
        }

        printf("\nEnter account number (-1 to exit): ");
        scanf("%d", &account_to_find);
    }

    fclose(fp);
}