/*
 A program to read a character from the console and display whether 
 the character is a lowercase vowel, an uppercase vowel, or other
 character. 

 Using nested if-else statement.
*/

#include <stdio.h>

int main(void)
{
  char ch;

  /* read a character */ 
  printf("Enter a character:\n");
  scanf("%c", &ch);

  /* check whether the character is a lowercase vowel,
     an uppercase vowel or other character */ 
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
  {   
    printf("Lowercase vowel\n");
  }
  else if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
  {
    printf("Uppercase vowel\n");
  }
  else
  {
    printf("Not a vowel\n");
  }

  return 0;
}
