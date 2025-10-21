
#include <stdio.h>

int main()
{
    int n = 0;
    printf("Enter a value for n:\n");
    scanf("%d", &n);
    
    if (n == 0) {
        printf("Invalid input");
    } else {
        
        for (int i = n; i != 0; i--) {
            for (int j = 0; j < i; j++) {
                printf("*-");
            }
            printf("\n");
        }
    }
    

    return 0;
}