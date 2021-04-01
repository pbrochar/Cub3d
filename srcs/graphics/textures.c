/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 12:32:26 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:04:05 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_get_color(t_main *main_struct, int i, int j, int y)
{
	if (y < main_struct->display->res_y && i < main_struct->display->res_x)
		main_struct->tex->color[j] = get_pxl_color(
			main_struct->texture[main_struct->ray->side],
			main_struct->tex->tex_x, main_struct->tex->tex_y);
}

static void	init_textures_calcul(t_main *main_struct)
{
	main_struct->tex->step = 1.0 * main_struct->texture
		[main_struct->ray->side]->height / main_struct->draw->line_height;
	if (main_struct->ray->side % 2 == 0 && main_struct->ray->ray_dir_x > 0)
		main_struct->tex->tex_x = main_struct->texture
		[main_struct->ray->side]->width - main_struct->tex->tex_x - 1;
	if (main_struct->ray->side % 2 == 1 && main_struct->ray->ray_dir_y < 0)
		main_struct->tex->tex_x = main_struct->texture
		[main_struct->ray->side]->width - main_struct->tex->tex_x - 1;
	if (main_struct->ray->side == 0 || main_struct->ray->side == 1)
		main_struct->tex->wall_x = main_struct->ray->pos_y
		+ main_struct->ray->perp_wall_dist * main_struct->ray->ray_dir_y;
	else
		main_struct->tex->wall_x = main_struct->ray->pos_x
		+ main_struct->ray->perp_wall_dist * main_struct->ray->ray_dir_x;
	main_struct->tex->wall_x -= floor(main_struct->tex->wall_x);
	main_struct->tex->tex_x = (int)(main_struct->tex->wall_x
		* (double)main_struct->texture[main_struct->ray->side]->width);
	main_struct->tex->tex_pos = (main_struct->draw->draw_start
	- main_struct->display->res_y / 2 + main_struct->draw->line_height / 2)
	* main_struct->tex->step;
}

int			*calcul_textures(t_main *main_struct, int i)
{
	int	y;
	int	j;

	init_textures_calcul(main_struct);
	j = 0;
	y = main_struct->draw->draw_start;
	main_struct->tex->color = malloc(sizeof(int)
			* main_struct->draw->line_height);
	if (main_struct->tex->color == NULL)
		return (NULL);
	while (y < main_struct->draw->draw_end)
	{
		if (main_struct->tex->tex_pos < 0)
			main_struct->tex->tex_y = 0;
		else
			main_struct->tex->tex_y = (int)main_struct->tex->tex_pos;
		main_struct->tex->tex_pos += main_struct->tex->step;
		check_get_color(main_struct, i, j, y);
		j++;
		y++;
	}
	return (main_struct->tex->color);
}
