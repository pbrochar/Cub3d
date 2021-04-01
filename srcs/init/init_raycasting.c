/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:04 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/24 14:34:24 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_step_side(t_main *main_struct)
{
	if (RAY_DIR_X < 0)
	{
		STEP_X = -1;
		SIDE_DIST_X = (POSX - MAPX) * DELTA_DIST_X;
	}
	else
	{
		STEP_X = 1;
		SIDE_DIST_X = (MAPX + 1.0 - POSX) * DELTA_DIST_X;
	}
	if (RAY_DIR_Y < 0)
	{
		STEP_Y = -1;
		SIDE_DIST_Y = (POSY - MAPY) * DELTA_DIST_Y;
	}
	else
	{
		STEP_Y = 1;
		SIDE_DIST_Y = (MAPY + 1.0 - POSY) * DELTA_DIST_Y;
	}
}

static void	init_delta_dist(t_main *main_struct)
{
	if (RAY_DIR_Y == 0)
		DELTA_DIST_X = 0;
	else
	{
		if (RAY_DIR_X == 0)
			DELTA_DIST_X = 1;
		else
			DELTA_DIST_X = fabs(1 / RAY_DIR_X);
	}
	if (RAY_DIR_X == 0)
		DELTA_DIST_Y = 0;
	else
	{
		if (RAY_DIR_Y == 0)
			DELTA_DIST_Y = 1;
		else
			DELTA_DIST_Y = fabs(1 / RAY_DIR_Y);
	}
}

void		init_raycasting(t_main *main_struct, int ray)
{
	MAPX = (int)POSX;
	MAPY = (int)POSY;
	CAMERA_X = 2 * ray / (double)RES_X - 1;
	RAY_DIR_X = DIRX + PLANEX * CAMERA_X;
	RAY_DIR_Y = DIRY + PLANEY * CAMERA_X;
	HIT = 0;
	init_delta_dist(main_struct);
	init_step_side(main_struct);
}
