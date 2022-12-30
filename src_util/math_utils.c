#include "includes.h"

double	absd(double a)
{
	return ((a < 0) * -a + (a >= 0) * a);
}