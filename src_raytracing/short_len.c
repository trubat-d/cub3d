#include "includes.h"

static double	find_vertical_len(double angle)
{
	double			xa;
	double			ya;
	t_posd			current;

	if (angle == 90 || angle == 270)
		return (10000);
	ya = MAP_SIZE * tan(angle_to_rad(angle));
	xa = MAP_SIZE;
	if (angle < 90 || angle > 270)
		ya *= -1;
	else if (angle < 180 && angle > 0)
		xa *= -1;
	get_first_vertical(&current, angle);
	mlx_print_point((t_posd){current.x, current.y},
		get_data(NULL)->mlx.player_pos.img,
		(t_color){0, 255, 255, 0});
	while (is_on_grid(current, 1, angle))
	{
		current.x = current.x + xa;
		current.y = current.y + ya;
	}
	return (get_len_pos(current));
}

static double	find_horizontal_len(double angle)
{
	double			xa;
	double			ya;
	t_posd			current;

	if (angle == 180 || angle == 0)
		return (10000);
	xa = MAP_SIZE / tan(angle_to_rad(angle));
	ya = MAP_SIZE;
	if (angle < 180 && angle > 0)
		ya *= -1;
	else if (angle < 90 || angle > 270)
		xa *= -1;
	get_first_horizontal(&current, angle);
	mlx_print_point((t_posd){current.x, current.y},
		get_data(NULL)->mlx.player_pos.img,
		(t_color){0, 255, 0, 0});
	while (is_on_grid(current, 2, angle))
	{
		current.x = current.x + xa;
		current.y = current.y + ya;
	}
	return (get_len_pos(current));
}

double	find_short_len(double angle)
{
	double	vertical_len;
	double	horizontal_len;

	horizontal_len = absd(find_horizontal_len(angle));
	vertical_len = absd(find_vertical_len(angle));
	return ((vertical_len < horizontal_len) * vertical_len
		+ (vertical_len >= horizontal_len) * horizontal_len);
}