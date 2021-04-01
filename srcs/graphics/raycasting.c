/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:45:10 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:45:58 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hit_wall_sprite(t_main *main_struct)
{
	if (ft_charischar(main_struct->level->map[main_struct->ray->map_y]
			[main_struct->ray->map_x], "02") == 0)
		main_struct->ray->hit = 1;
	else if (main_struct->level->map[main_struct->ray->map_y]
				[main_struct->ray->map_x] == '2')
		is_sprite(main_struct);
}

static void	hit_wall(t_main *main_struct)
{
	while (main_struct->ray->hit == 0)
	{
		if (main_struct->ray->side_dist_x < main_struct->ray->side_dist_y)
		{
			main_struct->ray->side_dist_x += main_struct->ray->delta_dist_x;
			main_struct->ray->map_x += main_struct->ray->step_x;
			if (main_struct->ray->step_x == 1)
				main_struct->ray->side = 0;
			else if (main_struct->ray->step_x == -1)
				main_struct->ray->side = 1;
		}
		else
		{
			main_struct->ray->side_dist_y += main_struct->ray->delta_dist_y;
			main_struct->ray->map_y += main_struct->ray->step_y;
			if (main_struct->ray->step_y == 1)
				main_struct->ray->side = 2;
			else if (main_struct->ray->step_y == -1)
				main_struct->ray->side = 3;
		}
		hit_wall_sprite(main_struct);
	}
}

static void	calcul_wall_dist(t_main *main_struct)
{
	if (main_struct->ray->side == 0 || main_struct->ray->side == 1)
		main_struct->ray->perp_wall_dist = (main_struct->ray->map_x
		- main_struct->ray->pos_x + (1 - main_struct->ray->step_x) / 2)
		/ main_struct->ray->ray_dir_x;
	else
		main_struct->ray->perp_wall_dist = (main_struct->ray->map_y
		- main_struct->ray->pos_y + (1 - main_struct->ray->step_y) / 2)
		/ main_struct->ray->ray_dir_y;
}

static void	calcul_draw_limits(t_main *main_struct)
{
	main_struct->draw->line_height = (int)(main_struct->display->res_y
	/ main_struct->ray->perp_wall_dist);
	main_struct->draw->draw_start = -main_struct->draw->line_height
	/ 2 + main_struct->display->res_y / 2;
	if (main_struct->draw->draw_start < 0)
		main_struct->draw->draw_start = 0;
	main_struct->draw->draw_end = main_struct->draw->line_height / 2
	+ main_struct->display->res_y / 2;
	if (main_struct->draw->draw_end >= main_struct->display->res_y)
		main_struct->draw->draw_end = main_struct->display->res_y - 1;
}

int			raycasting(t_main *main_struct)
{
	int		i;

	main_struct->ray->wall_dist_buf = malloc(sizeof(double)
	* main_struct->display->res_x);
	if (!main_struct->ray->wall_dist_buf)
		return (-1);
	i = 0;
	main_struct->sprite->nb_sprite = 0;
	while (i < main_struct->display->res_x)
	{
		init_raycasting(main_struct, i);
		hit_wall(main_struct);
		calcul_wall_dist(main_struct);
		main_struct->ray->wall_dist_buf[i] = main_struct->ray->perp_wall_dist;
		calcul_draw_limits(main_struct);
		if (draw_line(main_struct, i) == -1)
			return (-1);
		i++;
	}
	draw_sprite(main_struct);
	free(main_struct->ray->wall_dist_buf);
	return (0);
}
