#include <stdio.h>

typedef struct {
    char name[100];
    float price;
    int quantity;
} Product;

void getProductInput(Product *p) {
    printf("\nEnter product name: ");
    scanf("%s", p->name);
    printf("Enter price: ");
    scanf("%f", &p->price);
    printf("Enter quantity: ");
    scanf("%d", &p->quantity);
}

float calculateTotal(Product *p) {
    return p->price * p->quantity;
}

int main(void) {
    int numProducts;

    printf("How many products do you want to enter (1-10)? ");
    scanf("%d", &numProducts);

    if (numProducts < 1 || numProducts > 10) {
        printf("Invalid number. Setting to 1.\n");
        numProducts = 1;
    }

    // Declare an array of Structs
    Product inventory[10];

    // Loop to fill the array
    for (int i = 0; i < numProducts; i++) {
        printf("\n--- Product #%d ---", i + 1);
        // We pass the address of the specific element in the array
        getProductInput(&inventory[i]);
    }

    // Loop to display the results
    printf("\n%-20s %-10s %-10s %-10s\n", "Name", "Price", "Qty", "Total");
    printf("----------------------------------------------------------\n");

    float grandTotal = 0;
    for (int i = 0; i < numProducts; i++) {
        float total = calculateTotal(&inventory[i]);
        grandTotal += total;

        printf("%-20s $%-9.2f %-10d $%-10.2f\n",
               inventory[i].name,
               inventory[i].price,
               inventory[i].quantity,
               total);
    }

    printf("----------------------------------------------------------\n");
    printf("Grand Total Value: $%.2f\n", grandTotal);

    return 0;
}