/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:35:38 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:35:39 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage.h"

int	free_node(t_malloc *current)
{
	if (current->content)
		free(current->content);
	current->content = NULL;
	free(current);
	current = NULL;
	return (0);
}

int	del_malloc(void *element)
{
	int			pos;
	t_malloc	*current;
	t_malloc	*tmp;
	t_malloc	**root;

	if (!element)
		return (1);
	root = &(get_data(NULL)->garbage);
	pos = get_id_malloc(element);
	current = *root;
	if (pos < 0)
		return (1);
	if (pos == 0)
	{
		*root = current->next;
		free_node(current);
		return (0);
	}
	while (--pos > 0)
		current = current->next;
	tmp = current->next->next;
	free_node(current->next);
	current->next = tmp;
	return (0);
}

int	free_all(void)
{
	t_malloc	*current;
	t_malloc	*tmp;
	t_malloc	**root;

	root = &(get_data(NULL)->garbage);
	current = *root;
	while (current)
	{
		tmp = current->next;
		free_node(current);
		current = tmp;
	}
	*root = NULL;
	return (0);
}

int	free_mlx(void)
{
	t_data	*data;

	data = get_data(NULL);
	if (data->mlx.mlx && data->mlx.map.no_img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.map.no_img.img);
	if (data->mlx.mlx && data->mlx.map.so_img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.map.so_img.img);
	if (data->mlx.mlx && data->mlx.map.we_img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.map.we_img.img);
	if (data->mlx.mlx && data->mlx.map.ea_img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.map.ea_img.img);
	if (data->mlx.mlx && data->mlx.map.map_img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.map.map_img.img);
	if (data->mlx.mlx && data->mlx.player_pos.img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.player_pos.img.img);
	if (data->mlx.mlx && data->mlx.projection.img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.projection.img.img);
	if (data->mlx.mlx && data->mlx.background.img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.background.img.img);
	if (data->mlx.mlx && data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	return (0);
}
