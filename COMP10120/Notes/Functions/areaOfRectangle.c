#include <stdio.h>

double calcRectangleArea(double width, double height);

int main(void) {
    double width, height;

    printf("Enter the width of the rectangle: \n");
    scanf("%lf", &width);
    
    printf("Enter the height of the rectangle: \n");
    scanf("%lf", &height);


    double rectOne = calcRectangleArea(width, height);

    printf("The area of the rectangle is %.2lf", rectOne);

    return 0;
}

double calcRectangleArea(double width, double height) {
    return width * height;
}