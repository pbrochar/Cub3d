/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:07:20 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:19:44 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_plane(double plane_x, double plane_y, t_main *main_struct)
{
	main_struct->ray->plane_x = plane_x;
	main_struct->ray->plane_y = plane_y;
}

static void	get_dir(char c, t_main *main_struct)
{
	if (c == 'N')
	{
		main_struct->ray->dir_x = 0.0;
		main_struct->ray->dir_y = -1.0;
		get_plane(0.66, 0.0, main_struct);
	}
	else if (c == 'S')
	{
		main_struct->ray->dir_x = 0.0;
		main_struct->ray->dir_y = 1.0;
		get_plane(-0.66, 0.0, main_struct);
	}
	else if (c == 'E')
	{
		main_struct->ray->dir_x = 1.0;
		main_struct->ray->dir_y = 0.0;
		get_plane(0.0, 0.66, main_struct);
	}
	else if (c == 'W')
	{
		main_struct->ray->dir_x = -1.0;
		main_struct->ray->dir_y = 0.0;
		get_plane(0.0, -0.66, main_struct);
	}
}

void		get_pos_start(t_main *main_struct)
{
	int	i;
	int	j;

	i = 0;
	while (i < main_struct->level->y_max)
	{
		j = 0;
		while (j < main_struct->level->x_max)
		{
			if (ft_charischar(main_struct->level->map[i][j], "NSEW") == 1)
			{
				main_struct->ray->pos_x = (double)(j + 0.5);
				main_struct->ray->pos_y = (double)(i + 0.5);
				get_dir(main_struct->level->map[i][j], main_struct);
				main_struct->level->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
