/*
 * line.c

 *
 *  Created on: 19 Apr 2017
 *      Author: liliana
 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "line.h"


// calculate the slope of the line
double getSlope(double x1, double y1, double x2, double y2 ) {
	// avoid dividing by zero
	if(x1 == x2){
		perror("It is impossible to calculate the slope of a vertical line");
		return -1;
	}
	else return (y2 - y1) / (x2 - x1);
}

// calculate the perimeter of the line
double getDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}


