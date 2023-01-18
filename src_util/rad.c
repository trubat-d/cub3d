/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerdos-s <jerdos-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:40:22 by jerdos-s          #+#    #+#             */
/*   Updated: 2023/01/18 19:40:24 by jerdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

double	angle_to_rad(double angle)
{
	return (angle * (M_PI / 180.0));
}

double	rad_to_angle(double rad)
{
	return (rad * (180.0 / M_PI));
}
