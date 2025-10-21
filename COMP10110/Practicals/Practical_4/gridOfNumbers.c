
#include <stdio.h>

int main()
{
    int num = 7;
    
    for (int i = 0; i < 5; i++) {
        
        for (int j = 0; j < 4; j++) {
            printf("%4d", num);
            num += 3;
        }
        num -=5;
        printf("\n");
    }

    return 0;
}