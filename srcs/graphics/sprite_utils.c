/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:23:01 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:49:07 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			swap_point_tab(t_main *main_struct, int i, int j)
{
	t_point temp;

	temp.x = main_struct->sprite->sprite_tab[j].x;
	temp.y = main_struct->sprite->sprite_tab[j].y;
	main_struct->sprite->sprite_tab[j] = main_struct->sprite->sprite_tab[i];
	main_struct->sprite->sprite_tab[i].x = temp.x;
	main_struct->sprite->sprite_tab[i].y = temp.y;
}

static void		calcul_lim_sprite(t_main *main_struct, t_sprite_val *sprite)
{
	sprite->draw_start_y = -sprite->sprite_height
				/ 2 + main_struct->display->res_y / 2;
	if (sprite->draw_end_x < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->sprite_height
				/ 2 + main_struct->display->res_y / 2;
	if (sprite->draw_end_y >= main_struct->display->res_y)
		sprite->draw_end_y = main_struct->display->res_y - 1;
	sprite->sprite_width = abs((int)(main_struct->display->res_y
				/ sprite->transform_y));
	sprite->draw_start_x = -sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_end_x >= main_struct->display->res_x)
		sprite->draw_end_x = main_struct->display->res_x - 1;
}

t_sprite_val	initial_sprite_calculation(t_main *main_struct, int i)
{
	t_sprite_val sprite;

	sprite.sprite_x = main_struct->sprite->sprite_tab[i].x
						- main_struct->ray->pos_x + 0.5;
	sprite.sprite_y = main_struct->sprite->sprite_tab[i].y
						- main_struct->ray->pos_y + 0.5;
	sprite.inv_det = 1.0 / (main_struct->ray->plane_x
					* main_struct->ray->dir_y - main_struct->ray->dir_x
					* main_struct->ray->plane_y);
	sprite.transform_x = sprite.inv_det
							* (main_struct->ray->dir_y * sprite.sprite_x
							- main_struct->ray->dir_x * sprite.sprite_y);
	sprite.transform_y = sprite.inv_det
							* (-main_struct->ray->plane_y * sprite.sprite_x
							+ main_struct->ray->plane_x * sprite.sprite_y);
	sprite.sprite_screen_x = (int)(((double)main_struct->display->res_x / 2)
							* (1 + sprite.transform_x / sprite.transform_y));
	sprite.sprite_height = abs((int)((double)main_struct->display->res_y
								/ sprite.transform_y));
	calcul_lim_sprite(main_struct, &sprite);
	return (sprite);
}
