/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:32:53 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:21:22 by pbrochar         ###   ########.fr       */
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

	path[0] = NO_PATH;
	path[1] = SO_PATH;
	path[2] = WE_PATH;
	path[3] = EA_PATH;
	path[4] = SPRITE_PATH;
	i = 0;
	while (i < 5)
	{
		TEXTURES[i]->img =
		mlx_xpm_file_to_image(MLX, path[i], &(TEXTURES[i]->width),
		&TEXTURES[i]->height);
		TEXTURES[i]->addr =
		mlx_get_data_addr(TEXTURES[i]->img, &TEXTURES[i]->bits_per_pixel,
		&TEXTURES[i]->line_length, &TEXTURES[i]->endian);
		if (TEXTURES[i]->img == 0 || TEXTURES[i]->addr == 0)
			return (-1);
		i++;
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
		if (TEXTURES[i] == NULL)
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
	mlx_get_screen_size(MLX, &screen_size_x, &screen_size_y);
	if (RES_X > screen_size_x)
		RES_X = screen_size_x;
	if (RES_Y > screen_size_y)
		RES_Y = screen_size_y;
}

int			init_graphics(t_main *main_struct)
{
	MLX = mlx_init();
	if (MLX == 0)
		return (-1);
	check_update_screen_size(main_struct);
	WIN = mlx_new_window(MLX, RES_X, RES_Y, "cub3D");
	if (WIN == 0)
		return (-1);
	IMG = mlx_new_image(MLX, RES_X, RES_Y);
	if (IMG == 0)
		return (-1);
	ADDR = mlx_get_data_addr(IMG, &BPP, &LINE_LENGTH, &ENDIAN);
	if (ADDR == 0)
		return (-1);
	if (malloc_textures(main_struct) == -1)
		return (-1);
	if (malloc_sprite(main_struct) == -1)
		return (-1);
	return (0);
}
