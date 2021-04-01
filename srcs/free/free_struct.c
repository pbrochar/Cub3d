/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:09:53 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 15:59:27 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_texture_tab(t_main *main_struct)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (TEXTURES[i] != NULL)
		{
			mlx_destroy_image(MLX, TEXTURES[i]->img);
			free(TEXTURES[i]);
		}
		i++;
	}
}

static void	free_texture_path(t_main *main_struct)
{
	if (NO_PATH != NULL)
		free(NO_PATH);
	if (WE_PATH != NULL)
		free(WE_PATH);
	if (EA_PATH != NULL)
		free(EA_PATH);
	if (SO_PATH != NULL)
		free(SO_PATH);
	if (SPRITE_PATH != NULL)
		free(SPRITE_PATH);
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
	while (i < Y_MAX)
	{
		free(MAP[i]);
		i++;
	}
	free(MAP);
}

void		free_struct(t_main *main_struct)
{
	if (IMG != 0)
		mlx_destroy_image(MLX, IMG);
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
	if (WIN != 0)
		mlx_destroy_window(MLX, WIN);
	if (MLX != 0)
		mlx_destroy_display(MLX);
	free(MLX);
	if (main_struct->display != NULL)
		free(main_struct->display);
	if (main_struct != NULL)
		free(main_struct);
}
