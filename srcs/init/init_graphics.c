/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:32:53 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/06 15:05:42 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	malloc_sprite(t_main *main_struct)
{
	t_sprite *sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (-1);
	main_struct->sprite = sprite;
	main_struct->sprite->actual_map_x = -1;
	main_struct->sprite->actual_map_y = -1;
	main_struct->sprite->nb_sprite = 0;
	main_struct->sprite->sprite_list = NULL;
	return (0);
}

static int	init_textures(t_main *main_struct)
{
	int		i;
	char	*path[5];

	path[0] = main_struct->level->e_texture;
	path[1] = main_struct->level->w_texture;
	path[2] = main_struct->level->s_texture;
	path[3] = main_struct->level->n_texture;
	path[4] = main_struct->level->sprite;
	i = -1;
	while (++i < 5)
	{
		main_struct->texture[i]->img =
		mlx_xpm_file_to_image(main_struct->display->mlx, path[i],
									&(main_struct->texture[i]->width),
		&main_struct->texture[i]->height);
		main_struct->texture[i]->addr =
		mlx_get_data_addr(main_struct->texture[i]->img,
										&main_struct->texture[i]->bpp,
		&main_struct->texture[i]->line_length,
									&main_struct->texture[i]->endian);
		if (main_struct->texture[i]->img == 0
			|| main_struct->texture[i]->addr == 0)
			return (-1);
	}
	return (0);
}

static int	malloc_textures(t_main *main_struct)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		main_struct->texture[i] = malloc(sizeof(t_data));
		main_struct->texture[i]->img = NULL;
		main_struct->texture[i]->addr = NULL;
		if (main_struct->texture[i] == NULL)
			return (-1);
		i++;
	}
	if (init_textures(main_struct) == -1)
		return (-1);
	return (0);
}

static void	check_update_screen_size(t_main *main_struct)
{
	int screen_size_x;
	int screen_size_y;

	screen_size_x = 0;
	screen_size_y = 0;
	mlx_get_screen_size(main_struct->display->mlx,
							&screen_size_x, &screen_size_y);
	if (main_struct->display->res_x > screen_size_x)
		main_struct->display->res_x = screen_size_x;
	if (main_struct->display->res_y > screen_size_y)
		main_struct->display->res_y = screen_size_y;
}

int			init_graphics(t_main *main_struct)
{
	main_struct->display->mlx = mlx_init();
	if (main_struct->display->mlx == 0)
		return (-1);
	check_update_screen_size(main_struct);
	if (main_struct->save_bmp == 0)
	{
		main_struct->display->win = mlx_new_window(main_struct->display->mlx,
			main_struct->display->res_x, main_struct->display->res_y, "cub3D");
		if (main_struct->display->win == 0)
			return (-1);
	}
	main_struct->data->img = mlx_new_image(main_struct->display->mlx,
			main_struct->display->res_x, main_struct->display->res_y);
	if (main_struct->data->img == 0)
		return (-1);
	main_struct->data->addr = mlx_get_data_addr(main_struct->data->img,
		&main_struct->data->bpp, &main_struct->data->line_length,
		&main_struct->data->endian);
	if (main_struct->data->addr == 0)
		return (-1);
	if (malloc_textures(main_struct) == -1)
		return (-1);
	if (malloc_sprite(main_struct) == -1)
		return (-1);
	return (0);
}
