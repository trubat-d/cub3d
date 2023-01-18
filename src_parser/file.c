/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:09 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:10 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	open_file(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (1);
	return (0);
}

static int	get_path(char **res, char *buff)
{
	char	*pos;

	while (*buff && *buff != '.')
		buff++;
	if (!*buff)
	{
		ft_putstr_fd(2, "[ERROR]\tthe file is not relative path\n");
		return (1);
	}
	pos = ft_strchr(buff, '\n');
	if (pos)
		*pos = '\0';
	*res = buff;
	return (0);
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
		return ((int)ft_putstr_fd(2, "[ERROR]\terror to open file\n"));
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
