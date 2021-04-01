/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:50:07 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:59:34 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_char(t_main *main_struct)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < main_struct->level->y_max)
	{
		j = 0;
		while (main_struct->level->map[i][j])
		{
			if (ft_charischar(main_struct->level->map[i][j], "NSEW") == 1)
				count++;
			if (ft_charischar(main_struct->level->map[i][j], " 012NSEW") == 0)
				return (-1);
			j++;
		}
		if (count > 1)
			return (-1);
		i++;
	}
	if (count == 0)
		return (-1);
	return (0);
}

int	check_map_walls(t_main *main_struct)
{
	if (check_map_rows(main_struct) == -1)
		return (-1);
	if (check_map_columns(main_struct) == -1)
		return (-1);
	return (0);
}

int	check_map_rows(t_main *main_struct)
{
	int i;
	int j;

	i = 0;
	while (i < main_struct->level->y_max)
	{
		j = line_skip_space(main_struct->level->map[i]);
		if (j < main_struct->level->x_max
		&& main_struct->level->map[i][j] != '1')
			return (-1);
		while (j < main_struct->level->x_max)
		{
			if ((j = manage_zero_two_rows(main_struct, i, j)) == -1)
				return (-1);
			if (main_struct->level->map[i][j] == ' ')
			{
				if ((j = manage_space_rows(main_struct, i, j)) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_columns(t_main *main_struct)
{
	int	i;
	int	j;

	j = 0;
	while (j < main_struct->level->x_max)
	{
		i = skip_row_space(main_struct, 0, j);
		if (i < main_struct->level->y_max
			&& main_struct->level->map[i][j] != '1')
			return (-1);
		while (i < main_struct->level->y_max)
		{
			if ((i = manage_zero_two_columns(main_struct, i, j)) == -1)
				return (-1);
			if (main_struct->level->map[i][j] == ' ')
			{
				if ((i = manage_space_columns(main_struct, i, j)) == -1)
					return (-1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	skip_row_space(t_main *main_struct, int i, int j)
{
	int a;

	a = 0;
	while (i < main_struct->level->y_max
	&& ft_isspace(main_struct->level->map[i][j]))
	{
		i++;
		a++;
	}
	return (a);
}
