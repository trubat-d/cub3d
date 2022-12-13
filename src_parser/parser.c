#include "parser.h"

static int open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (1);
	return (0);
}

static int	open_image(char *buff)
{

	return (0);
}

static int	set_color(char *buff)
{
	int 	offset;
	t_color color;

	offset = 0;

	color.b = ft_atoi(buff + 1);

	if (ft_strncmp("F", buff, 2))
		bu
	if (ft_strncmp("C", buff, 2))

	return (0);
}

static int	check_is_set()
{
	t_data	*data;

	data = get_data(NULL);
	if (!data->mlx.map.no_img.img
		|| !data->mlx.map.so_img.img
		|| !data->mlx.map.we_img.img
		|| !data->mlx.map.ea_img.img
		|| data->mlx.background.ceiling.b == -1
		|| data->mlx.background.floor.b == -1)
		return (1);
	return (0);
}

int	init_map(void)
{
	int		fd;
	t_data	*data;
	char	*buff;

	data = get_data(NULL);
	data->mlx.background.ceiling.b = -1;
	data->mlx.background.floor.b = -1;
	if (open_file(&fd, data->file_map))
		return (1);
	while (ft_readline(fd, buff) && check_is_set())
	{
		if (!ft_strncmp("NO", buff, 2)
			|| !ft_strncmp("SO", buff, 2)
			|| !ft_strncmp("WE", buff, 2)
			|| !ft_strncmp("EA", buff, 2))
		{
			if (open_image(buff))
				return (1);
		}
		if (!ft_strncmp("F", buff, 1)
			|| !ft_strncmp("C", buff, 1))
		{
			if (set_color(buff))
				return (1);
		}
	}
	data = get_data(NULL);
	return (0);
}