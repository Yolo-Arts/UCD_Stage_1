
#include <stdio.h>

int main()
{
    int x;
    double sum = 0;
    double length = 0;
    printf("Enter an integer value:\n");
    scanf("%d", &x);
    
    if (x < 0) {
        printf("The mean is 0.0");
    } 
    else {
        while (x >= 0) {
            length += 1;
            sum += x;
            printf("Enter an integer value:\n");
            // printf("Sum: %d", sum);
            // printf("length: %d", length);
            scanf("%d", &x);
        }
        
        double mean = 0;
        mean = (sum / length);
        printf("The mean is %.1lf", mean);
    }
    
    

    return 0;
}