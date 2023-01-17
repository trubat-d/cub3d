#include "includes.h"

static void	condition_fill(int *tab, char c, t_pos pos, int *fill_x)
{
	int		tmp;
	t_data	*data;

	data = get_data(NULL);
	if (c == '1' || c == '0')
		tab[(*fill_x)++] = c - '0';
	else if (c == ' ')
		tab[(*fill_x)++] = -1;
	else if (c == '\t')
	{
		tmp = 0;
		while (tmp++ < 4)
			tab[(*fill_x)++] = -1;
	}
	else if (c == 'N')
	{
		tab[(*fill_x)++] = 0;
		data->mlx.player_pos.pos_player.x = pos.x * MAP_SIZE + MAP_SIZE / 2;
		data->mlx.player_pos.pos_player.y = pos.y * MAP_SIZE + MAP_SIZE / 2;
	}
}

void	fill_map(int *tab, char *current_map, int y)
{
	t_data	*data;
	int		str_x;
	int		fill_x;

	str_x = 0;
	fill_x = 0;
	data = get_data(NULL);
	while (current_map[str_x])
	{
		condition_fill(tab, current_map[str_x], (t_pos){str_x, y}, &fill_x);
		str_x++;
	}
	while (fill_x < data->mlx.map.col)
		tab[fill_x++] = -1;
}
