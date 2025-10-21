// #include <stdio.h>

// int main(void)
// {
// 	double temp_c, temp_f;

// 	/* Ask the user to input a temperature in Celsius */
// 	printf("Enter a temperature in Celsius:\n");
// 	scanf("%lf", &temp_c);

// 	/* Calculate the temperature in Fahrenheit */
    
//     temp_f = (temp_c * 1.8) + 32;
	
	
// 	/** Write your code here **/


// 	/* Display the temperature in Fahrenheit */
// 	printf("The temperature in Fahrenheit is: %.2lf\n", temp_f);

// 	return 0;
// }

#include <stdio.h>
#include <math.h>

int main(void)
{
	double r, area, volume;

	/* Ask the user to input a radius */
	printf("Enter a radius:\n");
	scanf("%lf", &r);

	
	/** Write your code here **/
    
    double base = M_PI * r;
    
    
    area = pow(base, 2);
    volume = pow((M_PI * (4/3) * r), 3);
    
    // The area is: 3.14
	// The volume is: 4.19
    
    printf("The area is: %d", area);
    printf("The volume is: %d", volume);
	

	return 0;
}
