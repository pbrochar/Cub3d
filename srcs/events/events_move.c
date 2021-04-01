/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:17:48 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:18:05 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_main *main_struct)
{
	if (MAP[(int)(POSY + DIRY * MOVE_SPEED)][(int)(POSX)] == '0')
		POSY += DIRY * MOVE_SPEED;
	if (MAP[(int)POSY][(int)(POSX + DIRX * MOVE_SPEED)] == '0')
		POSX += DIRX * MOVE_SPEED;
}

void	move_backward(t_main *main_struct)
{
	if (MAP[(int)(POSY - DIRY * MOVE_SPEED)][(int)(POSX)] == '0')
		POSY -= DIRY * MOVE_SPEED;
	if (MAP[(int)POSY][(int)(POSX - DIRX * MOVE_SPEED)] == '0')
		POSX -= DIRX * MOVE_SPEED;
}

void	move_right(t_main *main_struct)
{
	if (MAP[(int)(POSY)][(int)(POSX + PLANEX * MOVE_SPEED)] == '0')
		POSX += PLANEX * MOVE_SPEED;
	if (MAP[(int)(POSY + PLANEY * MOVE_SPEED)][(int)(POSX)] == '0')
		POSY += PLANEY * MOVE_SPEED;
}

void	move_left(t_main *main_struct)
{
	if (MAP[(int)POSY][(int)(POSX - PLANEX * MOVE_SPEED)] == '0')
		POSX -= PLANEX * MOVE_SPEED;
	if (MAP[(int)(POSY - PLANEY * MOVE_SPEED)][(int)POSX] == '0')
		POSY -= PLANEY * MOVE_SPEED;
}
