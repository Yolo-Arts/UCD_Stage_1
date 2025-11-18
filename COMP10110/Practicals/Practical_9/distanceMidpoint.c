#include <stdio.h>
#include <math.h>

typedef struct Point
{
	double x, y;
} Point;


/** Write your code here **/

Point midpoint(Point p1, Point p2);
double distance(Point p1, Point p2);

int main(void)
{
	Point p1, p2;

	/* read first point */
	printf("Enter the x and y coordinates of the first point:\n");
	scanf("%lf%lf", &p1.x, &p1.y);

	/* read second point */
	printf("Enter the x and y coordinates of the second point:\n");
	scanf("%lf%lf", &p2.x, &p2.y);


    /** Write your code here **/
    
    Point result = midpoint(p1, p2);
    printf("The midpoint is: (%.2lf, %.2lf)\n", result.x, result.y);
    
    
    double dist = distance(p1, p2);
    printf("The distance is: %.4lf", dist);

	return 0;
}


/** Write your code here **/

Point midpoint(Point p1, Point p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2.0;
    mid.y = (p1.y + p2.y) / 2.0;
    return mid;
}

double distance(Point p1, Point p2) {
    return sqrt(pow((p2.x - p1.x), 2.0) + pow((p2.y - p1.y), 2.0) );
}
