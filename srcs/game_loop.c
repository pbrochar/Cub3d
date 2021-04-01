/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:02:28 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 16:02:41 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_main *main_struct)
{
	raycasting(main_struct);
	mlx_hook(WIN, 33, (1L << 17), destroy_window, main_struct);
	mlx_hook(WIN, 3, (1L << 1), key_released, main_struct);
	mlx_hook(WIN, 2, (1L << 0), key_pressed, main_struct);
	mlx_loop_hook(MLX, events, main_struct);
	mlx_loop(MLX);
	return (0);
}
