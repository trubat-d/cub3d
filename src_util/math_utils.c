#include "includes.h"

double	absd(double a)
{
	return ((a < 0) * -a + (a >= 0) * a);
}

double	max_angle(double angle)
{
	if (angle >= 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}
