/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:18:21 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:03:04 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_main *main_struct)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = main_struct->ray->dir_x;
	old_plane_x = main_struct->ray->plane_x;
	main_struct->ray->dir_x = main_struct->ray->dir_x
	* cos(CONST_ROT_SPEED) - main_struct->ray->dir_y * sin(CONST_ROT_SPEED);
	main_struct->ray->dir_y = old_dir_x * sin(CONST_ROT_SPEED)
	+ main_struct->ray->dir_y * cos(CONST_ROT_SPEED);
	main_struct->ray->plane_x = main_struct->ray->plane_x
	* cos(CONST_ROT_SPEED) - main_struct->ray->plane_y * sin(CONST_ROT_SPEED);
	main_struct->ray->plane_y = old_plane_x
	* sin(CONST_ROT_SPEED) + main_struct->ray->plane_y * cos(CONST_ROT_SPEED);
}

void	rotate_left(t_main *main_struct)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = main_struct->ray->dir_x;
	old_plane_x = main_struct->ray->plane_x;
	main_struct->ray->dir_x = main_struct->ray->dir_x
	* cos(-CONST_ROT_SPEED) - main_struct->ray->dir_y * sin(-CONST_ROT_SPEED);
	main_struct->ray->dir_y = old_dir_x * sin(-CONST_ROT_SPEED)
	+ main_struct->ray->dir_y * cos(-CONST_ROT_SPEED);
	main_struct->ray->plane_x = main_struct->ray->plane_x
	* cos(-CONST_ROT_SPEED) - main_struct->ray->plane_y * sin(-CONST_ROT_SPEED);
	main_struct->ray->plane_y = old_plane_x * sin(-CONST_ROT_SPEED)
	+ main_struct->ray->plane_y * cos(-CONST_ROT_SPEED);
}
