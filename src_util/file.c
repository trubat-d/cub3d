#include "includes.h"

int open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (1);
	return (0);
}

static int	get_path(char **res, char *buff)
{
	while (*buff && *buff != '.')
		buff++;
	if (*buff)
	{
		*res = buff;
		return (0);
	}
	return (1);
}

int	open_image(char *buff)
{
	t_img	current_img;
	t_data	*data;
	char	*path;

	current_img = (t_img){};
	data = get_data(NULL);
	if (get_path(&path, buff))
		return (1);
	current_img.img = mlx_xpm_file_to_image(data->mlx.mlx,
			path, &current_img.width, &current_img.height);
	if (!current_img.img)
	{
		ft_putstr_fd(2, "[ERROR]\terror to open file");
		ft_putstr_fd(2, path);
		ft_putstr_fd(2, "\n");
		return (1);
	}
	if (!ft_strncmp("NO", buff, 2))
		data->mlx.map.no_img = current_img;
	if (!ft_strncmp("SO", buff, 2))
		data->mlx.map.so_img = current_img;
	if (!ft_strncmp("WE", buff, 2))
		data->mlx.map.we_img = current_img;
	if (!ft_strncmp("EA", buff, 2))
		data->mlx.map.ea_img = current_img;
	return (0);
}
