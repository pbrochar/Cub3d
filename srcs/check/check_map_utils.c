/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:18:33 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:00:41 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	manage_zero_two_rows(t_main *main_struct, int i, int j)
{
	while (main_struct->level->map[i][j] == '0'
			|| main_struct->level->map[i][j] == '2')
	{
		j++;
		if (main_struct->level->map[i][j] == '\0')
			return (-1);
	}
	return (j);
}

int	manage_space_rows(t_main *main_struct, int i, int j)
{
	if (main_struct->level->map[i][j - 1] != '1')
		return (-1);
	j += line_skip_space(&main_struct->level->map[i][j]);
	if (main_struct->level->map[i][j] != '\0'
		&& main_struct->level->map[i][j] != '1')
		return (-1);
	return (j);
}

int	manage_zero_two_columns(t_main *main_struct, int i, int j)
{
	while ((i < main_struct->level->y_max - 1)
			&& (main_struct->level->map[i][j] == '0'
			|| main_struct->level->map[i][j] == '2'))
	{
		i++;
		if (i == main_struct->level->y_max - 1
			&& (main_struct->level->map[i][j] == '0'
			|| main_struct->level->map[i][j] == '2'))
			return (-1);
	}
	return (i);
}

int	manage_space_columns(t_main *main_struct, int i, int j)
{
	if (main_struct->level->map[i - 1][j] != '1')
		return (-1);
	i += skip_row_space(main_struct, i, j);
	if (i < main_struct->level->y_max
		&& main_struct->level->map[i][j] != '\0'
		&& main_struct->level->map[i][j] != '1')
		return (-1);
	return (i);
}
