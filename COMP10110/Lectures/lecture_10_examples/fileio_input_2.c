/*
 This program reads data from a file which is formatted as 
 follows: each line contains an item id, the per unit cost 
 of that item, and the quantity of that item in stock. 

 For example, the file might look like this:

  100 1.00 1000
  200 25.99 18
  300 13.75 102
  400 40.99 88
  500 15.50 55

 The program outputs the total value of these items, which 
 is given by the sum of cost times quantity computed over 
 all items. 
*/

#include <stdio.h>

int main(void)
{
  int id, quantity;
  double cost, total_value = 0;

  /* 1. declare a pointer to a file */
  FILE *fp;

  /* 2. open file as an input file */
  fp = fopen("items.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file\n");
    return -1;
  }

  /* 3. read data from the file - here, fscanf reads 
        data into three variables */    
  while( fscanf(fp, "%d%lf%d", &id, &cost, &quantity) == 3 )
  {
    /* display data read from file */
    printf("%d %.2lf %d\n", id, cost, quantity);

    /* update total_value */
    total_value += cost * quantity;
  }

  printf("\nThe total value is %.2lf\n", total_value);

  /* 4. close the file now that we are finished with it */
  fclose(fp);

  return 0;
}

