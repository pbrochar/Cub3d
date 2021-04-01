/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:45:10 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:30:56 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hit_wall(t_main *main_struct)
{
	while (HIT == 0)
	{
		if (SIDE_DIST_X < SIDE_DIST_Y)
		{
			SIDE_DIST_X += DELTA_DIST_X;
			MAPX += STEP_X;
			if (STEP_X == 1)
				SIDE = 0;
			else if (STEP_X == -1)
				SIDE = 1;
		}
		else
		{
			SIDE_DIST_Y += DELTA_DIST_Y;
			MAPY += STEP_Y;
			if (STEP_Y == 1)
				SIDE = 2;
			else if (STEP_Y == -1)
				SIDE = 3;
		}
		if (MAP[MAPY][MAPX] != '0' && MAP[MAPY][MAPX] != '2')
			main_struct->ray->hit = 1;
		else if (MAP[MAPY][MAPX] != 0 && MAP[MAPY][MAPX] == '2')
			is_sprite(main_struct);
	}
}

static void	calcul_wall_dist(t_main *main_struct)
{
	if (SIDE == 0 || SIDE == 1)
		PERP_W_DIST = (MAPX - POSX + (1 - STEP_X) / 2) / RAY_DIR_X;
	else
		PERP_W_DIST = (MAPY - POSY + (1 - STEP_Y) / 2) / RAY_DIR_Y;
}

static void	calcul_draw_limits(t_main *main_struct)
{
	DRAW_LINE_HEIGHT = (int)(RES_Y / PERP_W_DIST);
	DRAW_START = -DRAW_LINE_HEIGHT / 2 + RES_Y / 2;
	if (DRAW_START < 0)
		DRAW_START = 0;
	DRAW_END = DRAW_LINE_HEIGHT / 2 + RES_Y / 2;
	if (DRAW_END >= RES_Y)
		DRAW_END = RES_Y - 1;
}

int			raycasting(t_main *main_struct)
{
	int		i;

	WALL_DIST_BUF = malloc(sizeof(double) * RES_X);
	if (!WALL_DIST_BUF)
		return (-1);
	i = 0;
	NB_SPRITE = 0;
	while (i < RES_X)
	{
		init_raycasting(main_struct, i);
		hit_wall(main_struct);
		calcul_wall_dist(main_struct);
		WALL_DIST_BUF[i] = PERP_W_DIST;
		calcul_draw_limits(main_struct);
		if (draw_line(main_struct, i) == -1)
			return (-1);
		i++;
	}
	draw_sprite(main_struct);
	free(WALL_DIST_BUF);
	if (main_struct->save_bmp == 1)
		if (create_bitmap(main_struct) == -1)
			return (-1);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
