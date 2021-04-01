/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:07:20 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/29 21:09:23 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_plane(double plane_x, double plane_y, t_main *main_struct)
{
	PLANEX = plane_x;
	PLANEY = plane_y;
}

static void	get_dir(char c, t_main *main_struct)
{
	if (c == 'N')
	{
		DIRX = 0.0;
		DIRY = -1.0;
		get_plane(0.66, 0.0, main_struct);
	}
	else if (c == 'S')
	{
		DIRX = 0.0;
		DIRY = 1.0;
		get_plane(-0.66, 0.0, main_struct);
	}
	else if (c == 'E')
	{
		DIRX = 1.0;
		DIRY = 0.0;
		get_plane(0.0, 0.66, main_struct);
	}
	else if (c == 'W')
	{
		DIRX = -1.0;
		DIRY = 0.0;
		get_plane(0.0, -0.66, main_struct);
	}
}

void		get_pos_start(t_main *main_struct)
{
	int	i;
	int	j;

	i = 0;
	while (i < Y_MAX)
	{
		j = 0;
		while (j < X_MAX)
		{
			if (ft_charischar(MAP[i][j], "NSEW") == 1)
			{
				POSX = (double)(j + 0.5);
				POSY = (double)(i + 0.5);
				get_dir(MAP[i][j], main_struct);
				MAP[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
