/*
 * triangle.c

 *
 *  Created on: 17 Apr 2017
 *      Author: liliana
 */

#include <stdio.h>
#include "triangle.h"

char * checkTriangle(int a, int b, int c){
	if(a == 90 || b == 90 || c == 90)
		return "Right";

	if(a == 60 && b == 60 && c == 60)
		return "Equilateral";

	if(a == b || b == c || c == a)
		return "Isosceles";

	return "Scalene";

}

