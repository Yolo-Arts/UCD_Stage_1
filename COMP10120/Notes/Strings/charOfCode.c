#include <stdio.h>

char char_of_code (unsigned charcode);

int main (void) {
    
    char result = char_of_code(65);
    printf("%c", result);
    return 0;
}

char char_of_code (unsigned charcode)
{
  char c = (char)charcode;
  return c;
}