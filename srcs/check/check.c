/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:08:24 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 15:37:23 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_r_value(char *line)
{
	int i;

	i = 1;
	while (ft_isdigit(line[i]) || line[i] == ' ')
		i++;
	if (line[i])
	{
		ft_printf(ERR_R_CUB);
		free(line);
		return (-1);
	}
	return (0);
}

int	check_fc_value(char *line)
{
	int i;

	i = 1;
	while (ft_isdigit(line[i]) || line[i] == ',' || ft_isspace(line[i]))
		i++;
	if (line[i] != '\0')
	{
		ft_printf(ERR_FC_CUB);
		free(line);
		return (-1);
	}
	return (0);
}

int	check_data(t_main *main_struct)
{
	if (NO_PATH == NULL || SO_PATH == NULL
		|| WE_PATH == NULL || EA_PATH == NULL
		|| SPRITE_PATH == NULL)
	{
		ft_printf(ERR_INC_CUB, "texture path (NO/SO/EA/WE/S)");
		return (-1);
	}
	else if (FCOLOR == -1 || CCOLOR == -1)
	{
		ft_printf(ERR_INC_CUB, "floor and sky colors (F/C)");
		return (-1);
	}
	else if (RES_X == -1 || RES_Y == -1)
	{
		ft_printf(ERR_INC_CUB, "window resolution (R)");
		return (-1);
	}
	return (0);
}

int	check_map(t_main *main_struct)
{
	if (check_map_char(main_struct) == -1)
	{
		ft_printf(ERR_INV_MAP);
		return (-1);
	}
	if (check_map_walls(main_struct) == -1)
	{
		ft_printf(ERR_INV_MAP);
		return (-1);
	}
	return (0);
}
