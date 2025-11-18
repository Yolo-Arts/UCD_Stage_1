#include <stdio.h>
#include <math.h>

void calculate_interest(double p, double r, int t, double *simple, double *compound);

int main(void)
{
	double principal, rate, simple_interest, compound_interest;
	int time;

	/* read values */
	printf("Enter the principal, rate, and time:\n");
	scanf("%lf%lf%d", &principal, &rate, &time);


	/** Write your code here - i.e. call function calculate_interest **/
    calculate_interest(principal, rate, time, &simple_interest, &compound_interest);

	/* display the result */
	printf("The simple interest is: %.2lf\n", simple_interest);
	printf("The compound interest is: %.2lf\n", compound_interest);

	return 0;
}

void calculate_interest(double p, double r, int t, double *simple, double *compound) 
{
    *simple = (p * r * t) / 100.0;
    
    *compound = p * pow(1 + r/100.0, t) - p;
}