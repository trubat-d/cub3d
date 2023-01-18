/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:41:57 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:41:57 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){};
	get_data(&data);
	if (valid_arg(argc, argv)
		|| init_map()
		|| init_mlx())
	{
		free_mlx();
		free_all();
		exit (1);
	}
	free_mlx();
	free_all();
	return (0);
}
