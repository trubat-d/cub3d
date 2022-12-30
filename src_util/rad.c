#include "includes.h"

double	angle_to_rad(double angle)
{
	return (angle * (M_PI / 180.0));
}

double	rad_to_angle(double rad)
{
	return (rad * (180.0 / M_PI));
}