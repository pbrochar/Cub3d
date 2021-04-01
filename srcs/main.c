/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:34:35 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 16:44:48 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_main	*main_struct;
	t_move	move;
	int		save_bmp;

	save_bmp = 0;
	if (check_args(argc, argv, &save_bmp) == -1)
		return (-1);
	if (init_struct(&main_struct, save_bmp) == -1
		|| parse_cub_file(argv[1], main_struct) == -1
		|| init_graphics(main_struct) == -1)
	{
		free_struct(main_struct);
		return (-1);
	}
	init_move_struct(&move, main_struct);
	get_pos_start(main_struct);
	if (save_bmp == 1)
	{
		if (create_bitmap(main_struct) == -1)
			return (-1);
	}
	else
		game_loop(main_struct);
	return (0);
}
