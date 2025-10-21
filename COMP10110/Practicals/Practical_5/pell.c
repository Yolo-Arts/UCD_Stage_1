#include <stdio.h>

int main(void)
{
    int prev = 0;
    int curr = 1;
    int prev2 = 0;
    int k;
    int i = 0;
    printf("Enter a value for k:\n");
    scanf("%d", &k);
    if (k == 0) {
        printf("Invalid input");
    } else {
        
        k = k -2;
        printf("%d ", prev);
        while (i <= k) {
            prev2 = curr;
            // printf("curr: %4d ", curr);
            // printf("prev: %4d ", prev);
            // printf("prev2: %4d\n", prev2);
            printf("%d ", curr);
            curr = (2 * prev2) + prev;
            prev = prev2;
            
            i++;
        }
        
    }

    return 0;
}