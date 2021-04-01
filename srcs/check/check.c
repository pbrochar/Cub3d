/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:08:24 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:31:58 by pbrochar         ###   ########.fr       */
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
	if (main_struct->level->n_texture == NULL
		|| main_struct->level->s_texture == NULL
		|| main_struct->level->w_texture == NULL
		|| main_struct->level->e_texture == NULL
		|| main_struct->level->sprite == NULL)
	{
		ft_printf(ERR_INC_CUB, "texture path (NO/SO/EA/WE/S)");
		return (-1);
	}
	else if (main_struct->level->fcolor == -1
			|| main_struct->level->ccolor == -1)
	{
		ft_printf(ERR_INC_CUB, "floor and sky colors (F/C)");
		return (-1);
	}
	else if (main_struct->display->res_x == -1
			|| main_struct->display->res_y == -1)
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
