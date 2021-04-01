/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:29:01 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:34:03 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_pxl_color(t_data *img, int x, int y)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void		pxl_put(t_main *main_struct, int x, int y, int color)
{
	char *dst;

	dst = main_struct->data->addr + (y * main_struct->data->line_length + x
			* (main_struct->data->bpp / 8));
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
	while (i < main_struct->draw->draw_start)
		pxl_put(main_struct, x, i++, main_struct->level->ccolor);
	while (i < main_struct->draw->draw_end)
	{
		pxl_put(main_struct, x, i++, color[j]);
		j++;
	}
	while (i <= main_struct->display->res_y)
		pxl_put(main_struct, x, i++, main_struct->level->fcolor);
	free(main_struct->tex->color);
	return (0);
}
