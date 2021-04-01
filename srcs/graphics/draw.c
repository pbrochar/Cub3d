/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:29:01 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:30:16 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_pxl_color(t_data *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void		pxl_put(t_main *main_struct, int x, int y, int color)
{
	char *dst;

	dst = ADDR + (y * LINE_LENGTH + x * (BPP / 8));
	*(unsigned int *)dst = color;
}

int			draw_line(t_main *main_struct, int x)
{
	int i;
	int j;
	int *color;

	j = 0;
	i = 0;
	color = calcul_textures(main_struct, x);
	if (color == NULL)
		return (-1);
	while (i < DRAW_START)
		pxl_put(main_struct, x, i++, CCOLOR);
	while (i < DRAW_END)
	{
		pxl_put(main_struct, x, i++, color[j]);
		j++;
	}
	while (i <= RES_Y)
		pxl_put(main_struct, x, i++, FCOLOR);
	free(COLOR_TAB);
	return (0);
}
