/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:04 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:18:15 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_step_side(t_main *main_struct)
{
	if (main_struct->ray->ray_dir_x < 0)
	{
		main_struct->ray->step_x = -1;
		main_struct->ray->side_dist_x = (main_struct->ray->pos_x
		- main_struct->ray->map_x) * main_struct->ray->delta_dist_x;
	}
	else
	{
		main_struct->ray->step_x = 1;
		main_struct->ray->side_dist_x = (main_struct->ray->map_x + 1.0
		- main_struct->ray->pos_x) * main_struct->ray->delta_dist_x;
	}
	if (main_struct->ray->ray_dir_y < 0)
	{
		main_struct->ray->step_y = -1;
		main_struct->ray->side_dist_y = (main_struct->ray->pos_y
		- main_struct->ray->map_y) * main_struct->ray->delta_dist_y;
	}
	else
	{
		main_struct->ray->step_y = 1;
		main_struct->ray->side_dist_y = (main_struct->ray->map_y
		+ 1.0 - main_struct->ray->pos_y) * main_struct->ray->delta_dist_y;
	}
}

static void	init_delta_dist(t_main *main_struct)
{
	if (main_struct->ray->ray_dir_y == 0)
		main_struct->ray->delta_dist_x = 0;
	else
	{
		if (main_struct->ray->ray_dir_x == 0)
			main_struct->ray->delta_dist_x = 1;
		else
			main_struct->ray->delta_dist_x = fabs(1
										/ main_struct->ray->ray_dir_x);
	}
	if (main_struct->ray->ray_dir_x == 0)
		main_struct->ray->delta_dist_y = 0;
	else
	{
		if (main_struct->ray->ray_dir_y == 0)
			main_struct->ray->delta_dist_y = 1;
		else
			main_struct->ray->delta_dist_y = fabs(1
										/ main_struct->ray->ray_dir_y);
	}
}

void		init_raycasting(t_main *main_struct, int ray)
{
	main_struct->ray->map_x = (int)main_struct->ray->pos_x;
	main_struct->ray->map_y = (int)main_struct->ray->pos_y;
	main_struct->ray->camera_x = 2 * ray
								/ (double)main_struct->display->res_x - 1;
	main_struct->ray->ray_dir_x = main_struct->ray->dir_x
				+ main_struct->ray->plane_x * main_struct->ray->camera_x;
	main_struct->ray->ray_dir_y = main_struct->ray->dir_y
				+ main_struct->ray->plane_y * main_struct->ray->camera_x;
	main_struct->ray->hit = 0;
	init_delta_dist(main_struct);
	init_step_side(main_struct);
}
