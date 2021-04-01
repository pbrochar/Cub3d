/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:18:33 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 15:33:57 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	manage_zero_two_rows(t_main *main_struct, int i, int j)
{
	while (MAP[i][j] == '0' || MAP[i][j] == '2')
	{
		j++;
		if (MAP[i][j] == '\0')
			return (-1);
	}
	return (j);
}

int	manage_space_rows(t_main *main_struct, int i, int j)
{
	if (MAP[i][j - 1] != '1')
		return (-1);
	j += line_skip_space(&MAP[i][j]);
	if (MAP[i][j] != '\0' && MAP[i][j] != '1')
		return (-1);
	return (j);
}

int	manage_zero_two_columns(t_main *main_struct, int i, int j)
{
	while ((i < Y_MAX - 1) && (MAP[i][j] == '0' || MAP[i][j] == '2'))
	{
		i++;
		if (i == Y_MAX - 1 && (MAP[i][j] == '0' || MAP[i][j] == '2'))
			return (-1);
	}
	return (i);
}

int	manage_space_columns(t_main *main_struct, int i, int j)
{
	if (MAP[i - 1][j] != '1')
		return (-1);
	i += skip_row_space(main_struct, i, j);
	if (i < Y_MAX && MAP[i][j] != '\0' && MAP[i][j] != '1')
		return (-1);
	return (i);
}
