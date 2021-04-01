/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:17:48 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:10:44 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_main *main_struct)
{
	if (main_struct->level->map[(int)(main_struct->ray->pos_y +
		main_struct->ray->dir_y * CONST_MOVE_SPEED)]
		[(int)(main_struct->ray->pos_x)] == '0')
		main_struct->ray->pos_y += main_struct->ray->dir_y * CONST_MOVE_SPEED;
	if (main_struct->level->map[(int)main_struct->ray->pos_y]
		[(int)(main_struct->ray->pos_x + main_struct->ray->dir_x
		* CONST_MOVE_SPEED)] == '0')
		main_struct->ray->pos_x += main_struct->ray->dir_x * CONST_MOVE_SPEED;
}

void	move_backward(t_main *main_struct)
{
	if (main_struct->level->map[(int)(main_struct->ray->pos_y
		- main_struct->ray->dir_y * CONST_MOVE_SPEED)]
		[(int)(main_struct->ray->pos_x)] == '0')
		main_struct->ray->pos_y -= main_struct->ray->dir_y * CONST_MOVE_SPEED;
	if (main_struct->level->map[(int)main_struct->ray->pos_y]
		[(int)(main_struct->ray->pos_x - main_struct->ray->dir_x
		* CONST_MOVE_SPEED)] == '0')
		main_struct->ray->pos_x -= main_struct->ray->dir_x * CONST_MOVE_SPEED;
}

void	move_right(t_main *main_struct)
{
	if (main_struct->level->map[(int)(main_struct->ray->pos_y)]
		[(int)(main_struct->ray->pos_x + main_struct->ray->plane_x
		* CONST_MOVE_SPEED)] == '0')
		main_struct->ray->pos_x += main_struct->ray->plane_x * CONST_MOVE_SPEED;
	if (main_struct->level->map[(int)(main_struct->ray->pos_y
		+ main_struct->ray->plane_y * CONST_MOVE_SPEED)]
		[(int)(main_struct->ray->pos_x)] == '0')
		main_struct->ray->pos_y += main_struct->ray->plane_y * CONST_MOVE_SPEED;
}

void	move_left(t_main *main_struct)
{
	if (main_struct->level->map[(int)main_struct->ray->pos_y]
		[(int)(main_struct->ray->pos_x - main_struct->ray->plane_x
		* CONST_MOVE_SPEED)] == '0')
		main_struct->ray->pos_x -= main_struct->ray->plane_x * CONST_MOVE_SPEED;
	if (main_struct->level->map[(int)(main_struct->ray->pos_y
		- main_struct->ray->plane_y * CONST_MOVE_SPEED)]
		[(int)main_struct->ray->pos_x] == '0')
		main_struct->ray->pos_y -= main_struct->ray->plane_y * CONST_MOVE_SPEED;
}
