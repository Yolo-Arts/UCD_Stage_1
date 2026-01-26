/*
 A program to read a character from the console and display whether 
 the character is a lowercase vowel, an uppercase vowel, or other
 character. 

 Using switch statement.
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
  switch (ch)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':  
      printf("Lowercase vowel\n");
      break;
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      printf("Uppercase vowel\n");
      break;    
    default:
      printf("Not a vowel\n");
  }

  return 0;
}
