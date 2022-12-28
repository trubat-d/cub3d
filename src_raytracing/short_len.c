#include "includes.h"

static double	find_vertical_len(double angle)
{
	char			neg;
	double			xa;
	double			ya;
	t_posd			current;

	neg = 1;
	if (angle > 90 && angle < 270)
		neg *= -1;
	ya = HEIGHT / tan(angle_to_rad(angle));
	xa = HEIGHT * neg;
	get_first_vertical(&current, angle, (neg < 0));
	while (is_on_grid(current))
	{
		current.x = current.x + xa;
		current.y = current.y + ya;
	}
	return (get_len_pos(current, angle));
}

static double	find_horizontal_len(double angle)
{
	char			neg;
	double			xa;
	double			ya;
	t_posd			current;

	neg = 1;
	if (angle < 180)
		neg *= -1;
	xa = HEIGHT / tan(angle_to_rad(angle));
	ya = HEIGHT * neg;
	get_first_horizontal(&current, angle, (neg < 0));
	while (is_on_grid(current))
	{
		current.x = current.x + xa;
		current.y = current.y + ya;
	}
	return (get_len_pos(current, angle));
}

double	find_short_len(double angle)
{
	double	vertical_len;
	double	horizontal_len;

	vertical_len = find_horizontal_len(angle);
	horizontal_len = find_vertical_len(angle);
	return ((vertical_len <= horizontal_len) * vertical_len
		+ (vertical_len > horizontal_len) * horizontal_len);
}