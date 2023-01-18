/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:33 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:34 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	mlx_relative_point_map(double angle, double distance, t_posd current,
	t_color color)
{
	int		size;
	double	opp;
	double	adj;
	t_rec	rec;

	size = 10;
	opp = absd(sin(angle_to_rad(angle)) * distance);
	adj = absd(cos(angle_to_rad(angle)) * distance);
	if (angle < 180 && angle > 0)
		current.y -= opp;
	else
		current.y += opp;
	if (angle < 270 && angle > 90)
		current.x -= adj;
	else
		current.x += adj;
	rec.pos = (t_pos){(int)current.x, (int)current.y};
	if (rec.pos.x >= MAP_SIZE / (size * 2))
		rec.pos.x -= (int)(MAP_SIZE / (size * 2));
	if (rec.pos.y >= MAP_SIZE / (size * 2))
		rec.pos.y -= (int)(MAP_SIZE / (size * 2));
	rec.heigth = MAP_SIZE / size;
	rec.width = MAP_SIZE / size;
	mlx_put_rec(get_data(NULL)->mlx.player_pos.img, rec, color);
	return (0);
}

int	mlx_relative_point(double angle, double distance, t_posd current,
		t_img img)
{
	double	opp;
	double	adj;
	t_rec	rec;

	if (!img.img)
		return (1);
	opp = absd(sin(angle_to_rad(angle)) * distance);
	adj = absd(cos(angle_to_rad(angle)) * distance);
	if (angle < 180 && angle > 0)
		current.y -= opp;
	else
		current.y += opp;
	if (angle < 270 && angle > 90)
		current.x -= adj;
	else
		current.x += adj;
	rec.pos = (t_pos){(int)current.x, (int)current.y};
	if (rec.pos.x >= MAP_SIZE / (5 * 2))
		rec.pos.x -= (int)(MAP_SIZE / (5 * 2));
	if (rec.pos.y >= MAP_SIZE / (5 * 2))
		rec.pos.y -= (int)(MAP_SIZE / (5 * 2));
	rec.heigth = MAP_SIZE / 5;
	rec.width = MAP_SIZE / 5;
	mlx_put_rec(img, rec, (t_color){0, 243, 156, 18});
	return (0);
}

int	mlx_print_point(t_posd current, t_img img, t_color color)
{
	t_data	*data;
	t_rec	rec;
	int		size;

	size = 20;
	if (!img.img)
		return (1);
	data = get_data(NULL);
	if (floor(current.y / MAP_SIZE) >= data->mlx.map.row
		|| floor(current.x / MAP_SIZE) >= data->mlx.map.col
		|| current.y < 0
		|| current.x < 0)
		return (0);
	rec.pos = (t_pos){(int)current.x, (int)current.y};
	if (rec.pos.x >= MAP_SIZE / (size * 2))
		rec.pos.x -= (int)(MAP_SIZE / (size * 2));
	if (rec.pos.y >= MAP_SIZE / (size * 2))
		rec.pos.y -= (int)(MAP_SIZE / (size * 2));
	rec.heigth = MAP_SIZE / size;
	rec.width = MAP_SIZE / size;
	mlx_put_rec(img, rec, color);
	return (0);
}
