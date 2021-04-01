/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:32:26 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/29 18:28:25 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_textures_calcul(t_main *main_struct)
{
	STEP = 1.0 * TEXTURES[SIDE]->height / DRAW_LINE_HEIGHT;
	if (SIDE % 2 == 0 && RAY_DIR_X > 0)
		TEX_X = TEXTURES[SIDE]->width - TEX_X - 1;
	if (SIDE % 2 == 1 && RAY_DIR_Y < 0)
		TEX_X = TEXTURES[SIDE]->width - TEX_X - 1;
	if (SIDE == 0 || SIDE == 1)
		WALL_X = POSY + PERP_W_DIST * RAY_DIR_Y;
	else
		WALL_X = POSX + PERP_W_DIST * RAY_DIR_X;
	WALL_X -= floor(WALL_X);
	TEX_X = (int)(WALL_X * (double)TEXTURES[SIDE]->width);
	TEX_POS = (DRAW_START - RES_Y / 2 + DRAW_LINE_HEIGHT / 2) * STEP;
}

int			*calcul_textures(t_main *main_struct, int i)
{
	int	y;
	int	j;

	init_textures_calcul(main_struct);
	j = 0;
	y = DRAW_START;
	COLOR_TAB = malloc(sizeof(int) * DRAW_LINE_HEIGHT);
	if (COLOR_TAB == NULL)
		return (NULL);
	while (y < DRAW_END)
	{
		if (TEX_POS < 0)
			TEX_Y = 0;
		else
			TEX_Y = (int)TEX_POS;
		TEX_POS += STEP;
		if (y < RES_Y && i < RES_X)
			COLOR_TAB[j] = get_pxl_color(TEXTURES[SIDE], TEX_X, TEX_Y);
		j++;
		y++;
	}
	return (COLOR_TAB);
}
