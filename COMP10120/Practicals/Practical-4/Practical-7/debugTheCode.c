/*

Debug the following code.

The input consists of five or more numbers:

The first number is the lower limit.
The second number is the upper limit.
The third number represents the number of divisors.
The fourth number onward contains the divisors (there may be more than one).
Ensure the program correctly handles the input and produces the expected output.

For example:

Input    Result
1 50000 2 3 5
The sum of numbers in the range given excluding those divisible by [ 3 5 ] is 666683332
1 10 2 3 5
The sum of numbers in the range given excluding those divisible by [ 3 5 ] is 22
1 10000 3 3 5 7
The sum of numbers in the range given excluding those divisible by [ 3 5 7 ] is 22852861
1 10000 0
Sum of numbers in the range given is 50005000
1 15 3 3 5 7
The sum of numbers in the range given excluding those divisible by [ 3 5 7 ]

*/


#include <stdio.h>

//Function protoypes
int userSum();

int main(void){

    userSum(); //Calling userSum() to let them enter their own sequence
}

int userSum(void){


    int sum = 0;
    int lower_limit = 0; //The starting number for range of numbers entered by the user
    int upper_limit = 0; //The end number for range of numbers entered by user
    int num_of_divisors = 0; //Number of divisors entered by user


    scanf("%d", &lower_limit);

    scanf("%d", &upper_limit);

    scanf("%d", &num_of_divisors);

    //If there are no divisors
    if (num_of_divisors == 0)
    {

        while (lower_limit <= upper_limit)
        { 

            sum += lower_limit; //add value of lower limit to sum
            lower_limit++; //Increment lower limit

        }

        printf("Sum of numbers in the range given is %u", sum); //Had to use %u as large numbers kept being displayed incorrectly
        return 1;

    }

    //Creating an array with size num_of_divisors to store the divisors given by user
    int divisors[num_of_divisors];
   
    for (int i = 0; i < num_of_divisors; i++)
    { //Reading in the divisors from the user and storing in the array divisors[]

        scanf("%d", &divisors[i]);

    }

    
    while (lower_limit <= upper_limit)
    {
       int flag = 0;

        for (int i = 0; i < num_of_divisors; i++)
        { //for loop to go through array of divisors
     
            if (lower_limit % divisors[i] == 0)
            { //if the current value of lower_limit is evenly divisible by the current
                                                 //divisor in divisors[i]
                flag = 1;
    
            }
        }

            if (flag ==0)
            { //if i is equal to the last number in divisors[] none of the numbers divide into
                                            //the current value of lower_limit

                sum += lower_limit; //add lower_limit to sum
            
            }
            
        

        lower_limit++; //Increment
    

    }

    printf("\nThe sum of numbers in the range given excluding those divisible by [");

    for (size_t i = 0; i < num_of_divisors; i++)
    {
        printf(" %d", divisors[i]);
    }

    printf(" ] is %u", sum); 

    
}