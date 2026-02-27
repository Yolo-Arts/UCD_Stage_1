#include <stdio.h>

typedef struct {
    char name[100];
    float price;
    int quantity;
} Product;

void getProductInput(Product *p) {
    printf("Enter the product name: \n");
    scanf("%s", p->name);
    printf("Enter the product's price: \n");
    scanf("%f", &p->price);
    printf("Enter the quanity of the product: \n");
    scanf("%d", &p->quantity);

    printf("Product initialised! \n");
}

float calculateTotal(Product *p) {
    return p->price * p->quantity;
}

int main(void) {

    Product newProduct;

    getProductInput(&newProduct);

    printf("Name: %s \n", newProduct.name);
    printf("Price: %.2f \n", newProduct.price);
    printf("Qauntity: %d \n", newProduct.quantity);
    printf("Total Price %.2f", calculateTotal(&newProduct));

    return 0;
}