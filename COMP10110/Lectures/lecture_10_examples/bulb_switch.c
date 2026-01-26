/*
 The lifetime of a light bulb is 5000h for a 25W bulb, 2000h for 
 40W and 60W bulbs and 1500h for 75W and 100W bulbs. 
 For a given wattage of a bulb, display the corresponding lifetime 
 to the console.

 Using switch statament.
*/

#include <stdio.h>

int main(void)
{
  int power_watts, life;

  /* read the wattage */
  printf("Enter the wattage:\n");
  scanf("%d", &power_watts);

  /* find the lifetime */ 
  switch (power_watts)
  {
    case 25:  
      life = 5000;
      break;
    case 40: 
    case 60:  
      life = 2000; 
      break;   
    case 75: 
    case 100: 
      life = 1500;
      break;
    default:  
      life = 0;
  }

  /* display result */
  printf("A bulb with wattage %d has a lifetime of %d hours\n", power_watts, life);
  
  return 0;
}
