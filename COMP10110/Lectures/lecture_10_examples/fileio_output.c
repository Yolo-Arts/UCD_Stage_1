#include <stdio.h>

#define N 10

int main(void)
{
  int i;

  /* 1. declare a pointer to a file */
  FILE *fp;

  /* 2. open file as an output file */
  fp = fopen("numbers.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening file\n");
    return -1;
  }

  /* 3. write data to the file */
  for (i = 0; i < N; i++)
  {
    fprintf(fp, "%d\n", i + 1);
  }

  /* 4. close the file now that we are finished with it */
  fclose(fp);

  return 0;
}
