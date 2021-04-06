/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:09:53 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/06 16:01:01 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_texture_tab(t_main *main_struct)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (main_struct->texture[i]->img != NULL)
		{
			mlx_destroy_image(main_struct->display->mlx,
											main_struct->texture[i]->img);
			free(main_struct->texture[i]);
		}
		else
			free(main_struct->texture[i]);
		i++;
	}
}

static void	free_texture_path(t_main *main_struct)
{
	if (main_struct->level->n_texture != NULL)
		free(main_struct->level->n_texture);
	if (main_struct->level->w_texture != NULL)
		free(main_struct->level->w_texture);
	if (main_struct->level->e_texture != NULL)
		free(main_struct->level->e_texture);
	if (main_struct->level->s_texture != NULL)
		free(main_struct->level->s_texture);
	if (main_struct->level->sprite != NULL)
		free(main_struct->level->sprite);
}

static void	free_struct_level(t_main *main_struct)
{
	free_map(main_struct);
	free_texture_path(main_struct);
	free(main_struct->level);
}

void		free_map(t_main *main_struct)
{
	int i;

	i = 0;
	while (i < main_struct->level->y_max)
	{
		free(main_struct->level->map[i]);
		i++;
	}
	free(main_struct->level->map);
}

void		free_struct(t_main *main_struct)
{
	if (main_struct->data->img != 0)
		mlx_destroy_image(main_struct->display->mlx, main_struct->data->img);
	if (main_struct->data != NULL)
		free(main_struct->data);
	if (main_struct->ray != NULL)
		free(main_struct->ray);
	if (main_struct->level != NULL)
		free_struct_level(main_struct);
	free_texture_tab(main_struct);
	if (main_struct->sprite != NULL)
		free(main_struct->sprite);
	if (main_struct->tex != NULL)
		free(main_struct->tex);
	if (main_struct->draw != NULL)
		free(main_struct->draw);
	if (main_struct->display->win != 0)
		mlx_destroy_window(main_struct->display->mlx,
									main_struct->display->win);
	if (main_struct->display->mlx != 0)
		mlx_destroy_display(main_struct->display->mlx);
	free(main_struct->display->mlx);
	if (main_struct->display != NULL)
		free(main_struct->display);
	if (main_struct != NULL)
		free(main_struct);
}
