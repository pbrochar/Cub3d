/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:18:21 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:18:35 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_main *main_struct)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = DIRX;
	old_plane_x = PLANEX;
	DIRX = DIRX * cos(ROT_SPEED) - DIRY * sin(ROT_SPEED);
	DIRY = old_dir_x * sin(ROT_SPEED) + DIRY * cos(ROT_SPEED);
	PLANEX = PLANEX * cos(ROT_SPEED) - PLANEY * sin(ROT_SPEED);
	PLANEY = old_plane_x * sin(ROT_SPEED) + PLANEY * cos(ROT_SPEED);
}

void	rotate_left(t_main *main_struct)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = DIRX;
	old_plane_x = PLANEX;
	DIRX = DIRX * cos(-ROT_SPEED) - DIRY * sin(-ROT_SPEED);
	DIRY = old_dir_x * sin(-ROT_SPEED) + DIRY * cos(-ROT_SPEED);
	PLANEX = PLANEX * cos(-ROT_SPEED) - PLANEY * sin(-ROT_SPEED);
	PLANEY = old_plane_x * sin(-ROT_SPEED) + PLANEY * cos(-ROT_SPEED);
}
