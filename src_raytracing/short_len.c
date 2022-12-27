#include "includes.h"

static float	find_vertical_len(double angle)
{

}

static float	find_horizontal_len(double angle)
{

}

float	find_short_len(double angle)
{
	double	vertical_len;
	double	horizontal_len;

	vertical_len = find_horizontal_len(angle);
	horizontal_len = find_vertical_len(angle);
	return ((vertical_len <= horizontal_len) * vertical_len
		+ (vertical_len > horizontal_len) * horizontal_len);
}