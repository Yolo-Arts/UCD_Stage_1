#include <stdio.h>

int main(void)
{
  int num;

  /* 1. declare a pointer to a file */
  FILE *fp;

  /* 2. open file as an input file */
  fp = fopen("numbers.txt", "r");
  if (fp == NULL)
  {
    printf("Error opening file\n");
    return -1;
  }

  /* 3. read data from the file */
  while ( fscanf(fp, "%d", &num) == 1 )
  {
    printf("%d\n", num);
  }
  
  /* 4. close the file now that we are finished with it */
  fclose(fp);

  return 0;
}

