#include "parser.h"

static int	set_color(char *buff)
{
	t_color		color;
	t_data		*data;

	data = get_data(NULL);
	color = (t_color){};
	color.r = ft_atoi(buff);
	color.g = ft_atoi(buff + size_nbr(color.r) + 2);
	color.b = ft_atoi(buff + size_nbr(color.r) + size_nbr(color.g) + 3);
	if (color.r > 255 || color.b > 255 || color.g > 255
		|| color.r == -1 || color.g == -1 || color.b == -1)
		return (-1);
	if (buff[0] == 'F')
		ft_memcpy(&data->mlx.background.floor, &color, sizeof(t_color));
	else if (buff[0] == 'C')
		ft_memcpy(&data->mlx.background.ceiling, &color, sizeof(t_color));
	return (0);
}

static int	check_is_set(int options)
{
	t_data	*data;

	data = get_data(NULL);
	if (options & 1)
	{
		if (data->mlx.background.ceiling.b == -1
			|| data->mlx.background.floor.b == -1)
			return (1);
	}
	if (options & 2)
	{
		if (!data->mlx.map.no_img.img
			|| !data->mlx.map.so_img.img
			|| !data->mlx.map.we_img.img
			|| !data->mlx.map.ea_img.img)
			return (1);
	}
	return (0);
}

static int	set_texture(int fd, char **buff)
{
	char	*res;

	while (!ft_readline(fd, buff, &res) && check_is_set(3))
	{
		if (!ft_strncmp("NO", res, 2)
			|| !ft_strncmp("SO", res, 2)
			|| !ft_strncmp("WE", res, 2)
			|| !ft_strncmp("EA", res, 2))
		{
			if (open_image(res))
				return (1);
		}
		if (!ft_strncmp("F", res, 1)
			|| !ft_strncmp("C", res, 1))
		{
			if (set_color(res))
				return ((int)ft_putstr_fd(2, "[ERROR]\terror color\n") + 1);
		}
		del_malloc(res);
	}
	if (check_is_set(3))
		return ((int)ft_putstr_fd(2, "[ERROR]\terror texture\n") + 1);
	return (0);
}

static int	set_map(int fd, char **buff)
{
	char	**map;

	if (get_map(fd, &map, buff)
		|| get_len_map(map)
		|| parse_current_map(map)
		|| free_map(map))
	{
		ft_putstr_fd(2, "[ERROR]\terror during parsing map\n");
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}

static int	set_addr(void)
{
	t_data	*data;
	t_img	*current;

	data = get_data(NULL);
	current = &data->mlx.map.we_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	current = &data->mlx.map.so_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	current = &data->mlx.map.no_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	current = &data->mlx.map.ea_img;
	current->addr = mlx_get_data_addr(current->img, &(current->bits_per_pixel),
			&(current->line_length), &(current->endian));
	return (0);
}

int	init_map(void)
{
	int		fd;
	t_data	*data;
	char	*buff;

	buff = NULL;
	data = get_data(NULL);
	data->mlx.mlx = mlx_init();
	data->mlx.background.ceiling.b = -1;
	data->mlx.background.floor.b = -1;
	if (open_file(&fd, data->file_map)
		|| set_texture(fd, &buff)
		|| set_addr()
		|| set_map(fd, &buff))
		return (1);
	if (buff)
		del_malloc((void *)buff);
	data->player.fov = DEFAULT_FOV;
	data->player.projection.col = WIDTH;
	data->player.projection.row = HEIGHT;
	data->player.current_pos.x = (double)data->mlx.player_pos.pos_player.x;
	data->player.current_pos.y = (double)data->mlx.player_pos.pos_player.y;
	return (0);
}
