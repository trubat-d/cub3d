#include "parser.h"

static int	set_color(char *buff)
{
	t_color		color;
	t_data		*data;

	buff++;
	data = get_data(NULL);
	color.r = ft_atoi(buff);
	color.g = ft_atoi(buff + size_nbr(color.r) + 1);
	color.b = ft_atoi(buff + size_nbr(color.r) + size_nbr(color.g) + 2);
	if (color.r == -1 || color.g == -1 || color.b == -1)
		return (-1);
	if (ft_strncmp("F", buff, 2))
		data->mlx.background.floor = color;
	if (ft_strncmp("C", buff, 2))
		data->mlx.background.ceiling = color;
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

	while (!ft_readline(fd, buff, &res) && check_is_set(1))
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
				return (1);
		}
		del_malloc(res);
	}
	if (check_is_set(1))
		return (1);
	return (0);
}

int	set_map(int fd, char **buff)
{
	char	**map;

	if (get_map(fd, &map, buff))
		return (1);
	//TODO: PARSER MAP CHAR **
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
	if (open_file(&fd, data->file_map))
		return (1);
	if (set_texture(fd, &buff))
		return (1);
	if (set_map(fd, &buff))
		return (1);
	if (buff)
		del_malloc((void *)buff);
	return (0);
}