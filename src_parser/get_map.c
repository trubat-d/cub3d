#include "includes.h"

static int	ft_strjoin_free(char **final, char *res)
{
	char	*tmp;

	if (ft_strjoin(&tmp, *final, res))
		return (1);
	del_malloc(*final);
	del_malloc(res);
	*final = tmp;
	return (0);
}

int	get_map(int fd, char ***map, char **buff)
{
	char	*final;
	char	*res;

	final = NULL;
	while (!ft_readline(fd, buff, &res))
	{
		if (ft_strjoin_free(&final, res))
			return (1);
		del_malloc(res);
	}
	if (*buff)
		if (ft_strjoin_free(&final, *buff))
			return (1);
	if (ft_split(map, final, '\n'))
		return (1);
	del_malloc(final);
	return (0);
}

int get_len_map(char **map)
{
	t_data	*data;
	int 	tmp_size;
	int 	*x;
	int 	*y;

	data = get_data(NULL);
	x = &data->mlx.map.col;
	y = &data->mlx.map.row;
	while (map[*y])
	{
		tmp_size = ft_strlen_map(map[*y]);
		if (tmp_size < 0)
			return (1);
		if (tmp_size > *x)
			*x = tmp_size;
		(*y)++;
	}
	return (0);
}

int parse_current_map(char **map)
{
	int 	y;
	t_data	*data;

	y = 0;
	data = get_data(NULL);
	if (ft_calloc((void **)&data->mlx.map.mapping, sizeof(int *), data->mlx.map.row))
		return (1);
	while (y < data->mlx.map.row)
	{
		if (ft_calloc((void **)&data->mlx.map.mapping[y], sizeof(int), data->mlx.map.col))
			return (1);
		fill_map(data->mlx.map.mapping[y], map[y], y);
		y++;
	}
	return (0);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		del_malloc(map[i++]);
	del_malloc(map);
	return (0);
}