#include "includes.h"

int	is_on_grid(t_posd pos)
{
	t_pos	map_pos;
	int		**map;

	map = get_data(NULL)->mlx.map.mapping;
	map_pos.x = (int)floor(pos.x / HEIGHT);
	map_pos.y = (int)floor(pos.y / HEIGHT);
	return (map[map_pos.x][map_pos.y] == 0);
}

double	get_len_pos(t_posd pos, double angle)
{
	t_posd	player_pos;
	t_posd	calc;

	player_pos = get_data(NULL)->player.current_pos;
	calc.x = pow(player_pos.x - pos.x, 2);
	calc.y = pow(player_pos.y - pos.y, 2);
	return (sqrt(calc.x + calc.y) * cos(angle_to_rad(angle)));
}

void	get_first_horizontal(t_posd *pos, double angle, int neg)
{
	t_data	*data;

	data = get_data(NULL);
	pos->y = floor(data->player.current_pos.y / HEIGHT);
	pos->y *= HEIGHT;
	if (neg)
		pos->y -= 1;
	else
		pos->y += HEIGHT;
	pos->x = data->player.current_pos.y - pos->y;
	pos->x = floor(pos->x / tan(angle_to_rad(angle)));  //TODO: check is correct implementation
	pos->x += data->player.current_pos.x;
}

void	get_first_vertical(t_posd *pos, double angle, int neg)
{
	t_data	*data;

	data = get_data(NULL);
	pos->x = floor(data->player.current_pos.x / HEIGHT);
	pos->x *= HEIGHT;
	if (neg)
		pos->x -= 1;
	else
		pos->x += HEIGHT;
	pos->y = data->player.current_pos.x - pos->x;
	pos->y = floor(pos->y * tan(angle_to_rad(angle))); //TODO: check is correct implementation
	pos->y += data->player.current_pos.y;
}
