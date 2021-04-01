/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:23:01 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/29 18:28:11 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			swap_point_tab(t_main *main_struct, int i, int j)
{
	t_point temp;

	temp.x = SPRITE_TAB[j].x;
	temp.y = SPRITE_TAB[j].y;
	SPRITE_TAB[j] = SPRITE_TAB[i];
	SPRITE_TAB[i].x = temp.x;
	SPRITE_TAB[i].y = temp.y;
}

static void		calcul_lim_sprite(t_main *main_struct, t_sprite_val *sprite)
{
	sprite->draw_start_y = -sprite->sprite_height / 2 + RES_Y / 2;
	if (sprite->draw_end_x < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->sprite_height / 2 + RES_Y / 2;
	if (sprite->draw_end_y >= RES_Y)
		sprite->draw_end_y = RES_Y - 1;
	sprite->sprite_width = abs((int)(RES_Y / sprite->transform_y));
	sprite->draw_start_x = -sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_end_x >= RES_X)
		sprite->draw_end_x = RES_X - 1;
}

t_sprite_val	initial_sprite_calculation(t_main *main_struct, int i)
{
	t_sprite_val sprite;

	sprite.sprite_x = SPRITE_TAB[i].x - POSX + 0.5;
	sprite.sprite_y = SPRITE_TAB[i].y - POSY + 0.5;
	sprite.inv_det = 1.0 / (PLANEX * DIRY - DIRX * PLANEY);
	sprite.transform_x = sprite.inv_det
							* (DIRY * sprite.sprite_x - DIRX * sprite.sprite_y);
	sprite.transform_y = sprite.inv_det
							* (-PLANEY * sprite.sprite_x
							+ PLANEX * sprite.sprite_y);
	sprite.sprite_screen_x = (int)(((double)RES_X / 2)
							* (1 + sprite.transform_x / sprite.transform_y));
	sprite.sprite_height = abs((int)((double)RES_Y / sprite.transform_y));
	calcul_lim_sprite(main_struct, &sprite);
	return (sprite);
}
