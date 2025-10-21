#include <stdio.h>

int main()
{
    double n1 = 0;
    double n2 = 0;
    double mean = 0.0;
    int valid = 0;
    
    int counter = 1;
    double zero_counter = 0.0;
    double sum = 0.0;
    
    printf("Enter n1:\n");
    scanf("%lf", &n1);
    printf("Enter n2:\n");
    scanf("%lf", &n2);
    counter = n1;
    
    while (valid == 0) {
        if (((n1 && n2) < 1) || (n1 == n2) || (n1 > n2)) {
            printf("Invalid input\n");
            printf("Enter n1:\n");
            scanf("%lf", &n1);
            printf("Enter n2:\n");
            scanf("%lf", &n2);
            counter = n1;
        }   else {
            
            while (counter <= n2) {
                // printf("Counter: %d\n", counter);
                if (counter % 3 == 0) {
                    sum += counter;
                    zero_counter += 1;
                    // printf("Counter divisible by 3: %d\n", counter);
                    // printf("sum: %f\n", sum);
                    // printf("Items to mean %f\n", zero_counter);
                } else if (counter % 4 == 0) {
                    sum += counter;
                    zero_counter += 1;
                    // printf("Counter divisible by 4: %d\n", counter);
                    // printf("sum: %f\n", sum);
                    // printf("Items to mean %f\n", zero_counter);
                } else if ((counter % 3 == 0) && (counter % 4 == 0)) {
                    sum += counter;
                    zero_counter += 1; 
                } 
                    
                
                counter += 1;
            }
            
            
            valid = 1;
            
        }
        
    }
    
    // printf("Sum is: %f\n", sum);
    // printf("zero_counter is: %f\n", zero_counter);
    
    if (sum == 0){
        mean = 0;
    } else {
        
        mean = sum / zero_counter;
    }
    

    
    // if ((n1 && n2) % 3 == 0 || (n1 && n2) % 4 == 0) {
    //     mean = (n1 + n2) / 2;
    // }
    
    
    printf("The mean is %.2lf", mean);

    return 0;
}