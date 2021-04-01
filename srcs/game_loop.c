/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:02:28 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:04:58 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_main *main_struct)
{
	raycasting(main_struct);
	mlx_hook(main_struct->display->win, 33, (1L << 17),
												destroy_window, main_struct);
	mlx_hook(main_struct->display->win, 3, (1L << 1),
													key_released, main_struct);
	mlx_hook(main_struct->display->win, 2, (1L << 0), key_pressed, main_struct);
	mlx_loop_hook(main_struct->display->mlx, events, main_struct);
	mlx_loop(main_struct->display->mlx);
	return (0);
}
