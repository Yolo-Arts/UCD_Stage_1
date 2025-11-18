#include <stdio.h>
#include <math.h>


/** Write your code here **/
typedef struct Cylinder {
    double radius, height;
} Cylinder;

void compute_volume_surface_area(Cylinder c, double *volume, double *surface_area);

int main(void)
{
	Cylinder c;

	/* read the radius and height */
	printf("Enter the radius and height:\n");
	scanf("%lf%lf", &c.radius, &c.height);


    /** Write your code here **/
    double volume_c, surface_area_c;
    
    compute_volume_surface_area(c, &volume_c, &surface_area_c);
    
    printf("The volume is: %.2lf\n", volume_c);
    printf("The surface area is: %.2lf", surface_area_c);
    
	return 0;
}


/** Write your code here **/

void compute_volume_surface_area(Cylinder c, double *volume, double *surface_area) {
    *volume = M_PI * pow(c.radius, 2) * c.height;
    *surface_area = 2 * M_PI * c.radius * (c.radius + c.height);
}