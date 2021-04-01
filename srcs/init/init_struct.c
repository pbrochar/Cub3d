/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:22:47 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 20:47:20 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_struct_str(t_main **main_struct)
{
	(*main_struct)->level->n_texture = NULL;
	(*main_struct)->level->s_texture = NULL;
	(*main_struct)->level->w_texture = NULL;
	(*main_struct)->level->e_texture = NULL;
	(*main_struct)->level->sprite = NULL;
	(*main_struct)->level->map = NULL;
}

static void	init_struct_int(t_main **main_struct)
{
	(*main_struct)->display->res_x = -1;
	(*main_struct)->display->res_y = -1;
	(*main_struct)->level->ccolor = -1;
	(*main_struct)->level->fcolor = -1;
	(*main_struct)->level->x_max = 0;
	(*main_struct)->level->y_max = 0;
	(*main_struct)->ray->move_speed = CONST_MOVE_SPEED;
	(*main_struct)->ray->rot_speed = CONST_ROT_SPEED;
}

static void	init_struct_null(t_main **main_struct)
{
	int i;

	i = 0;
	(*main_struct)->data->img = NULL;
	(*main_struct)->sprite = NULL;
	(*main_struct)->display->mlx = NULL;
	(*main_struct)->display->win = NULL;
	while (i < 5)
	{
		(*main_struct)->texture[i] = NULL;
		i++;
	}
}

int			init_struct(t_main **main_struct, int save_bmp)
{
	*main_struct = malloc(sizeof(t_main));
	if (*main_struct == NULL)
		return (-1);
	if (((*main_struct)->display = malloc(sizeof(t_disp))) == NULL)
		return (-1);
	if (((*main_struct)->data = malloc(sizeof(t_data))) == NULL)
		return (-1);
	if (((*main_struct)->level = malloc(sizeof(t_level))) == NULL)
		return (-1);
	if (((*main_struct)->ray = malloc(sizeof(t_ray))) == NULL)
		return (-1);
	if (((*main_struct)->draw = malloc(sizeof(t_draw))) == NULL)
		return (-1);
	if (((*main_struct)->tex = malloc(sizeof(t_tex))) == NULL)
		return (-1);
	(*main_struct)->save_bmp = save_bmp;
	init_struct_null(main_struct);
	init_struct_str(main_struct);
	init_struct_int(main_struct);
	return (0);
}
