#include <stdio.h>
#include <stdbool.h>


/** Write your code here **/
bool is_prime(int num);

int main(void)
{
	int k;
	int counter = 0;

	/* read a value for k */
	printf("Enter a value for k:\n");
	scanf("%d", &k);

	
	/** Write your code here **/
	
	printf("The first %d prime numbers are: ", k);
	
	for (int i = 2; counter != k; i++) {
	    bool result = is_prime(i);
	    
	    if (result) {
	        printf("%d ", i);
	        counter++;
	    }
	}
	
	return 0;
}


/** Write your code here **/

bool is_prime(int num) {
    
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i * i <= num; i++) {
        
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;

    
    
}