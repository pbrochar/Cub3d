/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:46:43 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 15:44:34 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_move_struct(t_move *move, t_main *main_struct)
{
	move->backward = 0;
	move->forward = 0;
	move->right = 0;
	move->left = 0;
	move->rotate_right = 0;
	move->rotate_left = 0;
	main_struct->move = move;
}

int		key_pressed(int key, t_main *main_struct)
{
	if (key == KEY_ESC)
	{
		free_struct(main_struct);
		exit(0);
	}
	if (key == KEY_FORWARD && main_struct->move->forward == 0)
		main_struct->move->forward = 1;
	else if (key == KEY_BACKWARD && main_struct->move->backward == 0)
		main_struct->move->backward = 1;
	else if (key == KEY_RIGHT_SIDE && main_struct->move->right == 0)
		main_struct->move->right = 1;
	else if (key == KEY_LEFT_SIDE && main_struct->move->left == 0)
		main_struct->move->left = 1;
	else if (key == KEY_CAM_RIGHT && main_struct->move->rotate_right == 0)
		main_struct->move->rotate_right = 1;
	else if (key == KEY_CAM_LEFT && main_struct->move->rotate_left == 0)
		main_struct->move->rotate_left = 1;
	return (0);
}

int		key_released(int key, t_main *main_struct)
{
	if (key == KEY_FORWARD && main_struct->move->forward == 1)
		main_struct->move->forward = 0;
	else if (key == KEY_BACKWARD && main_struct->move->backward == 1)
		main_struct->move->backward = 0;
	else if (key == KEY_RIGHT_SIDE && main_struct->move->right == 1)
		main_struct->move->right = 0;
	else if (key == KEY_LEFT_SIDE && main_struct->move->left == 1)
		main_struct->move->left = 0;
	else if (key == KEY_CAM_RIGHT && main_struct->move->rotate_right == 1)
		main_struct->move->rotate_right = 0;
	else if (key == KEY_CAM_LEFT && main_struct->move->rotate_left == 1)
		main_struct->move->rotate_left = 0;
	return (0);
}

int		destroy_window(t_main *main_struct)
{
	free_struct(main_struct);
	exit(0);
}

int		events(t_main *main_struct)
{
	if (main_struct->move->forward == 1)
		move_forward(main_struct);
	if (main_struct->move->backward == 1)
		move_backward(main_struct);
	if (main_struct->move->right == 1)
		move_right(main_struct);
	if (main_struct->move->left == 1)
		move_left(main_struct);
	if (main_struct->move->rotate_right == 1)
		rotate_right(main_struct);
	if (main_struct->move->rotate_left == 1)
		rotate_left(main_struct);
	raycasting(main_struct);
	return (0);
}
