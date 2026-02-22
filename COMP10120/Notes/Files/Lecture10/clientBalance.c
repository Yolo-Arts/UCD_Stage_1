#include <stdio.h>

int main(void) {
    FILE *cfPtr;

    if ((cfPtr = fopen("clients.txt", "w")) == NULL ) {
        printf("File could not be opened");
    } else {
        printf("Enter the account, name, and balance.\n");
        printf("Enter EOF to end input.\n");
        printf("? ");

        unsigned int account;
        char name[30];
        double balance;

        // name does not need & symbol as it is a pointer to the first index.
        scanf("%d%29s%lf", &account, name, &balance);

        while (!feof(stdin)) {
            fprintf(cfPtr, "%-10d %-30s %10.2f\n", account, name, balance);
            printf("? ");
            scanf("%d%29s%lf", &account, name, &balance);
        }

        fclose(cfPtr);

    }

    return 0;
}