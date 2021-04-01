/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_param_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:37:51 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 16:17:42 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_value_in_struct(char *line, int i, t_main *main_struct)
{
	if (line[i] == 'R')
		if (add_r_value(&line[i], main_struct) == -1)
			return (-1);
	if (line[i] == 'F' || line[i] == 'C')
		if (add_fc_value(&line[i], main_struct) == -1)
			return (-1);
	if (line_is_texture(&line[i]))
		parse_texture_path(&line[i], main_struct);
	return (0);
}

int	add_fc_value(char *line, t_main *main_struct)
{
	int r;
	int g;
	int b;

	if (check_fc_value(line) == -1)
		return (-1);
	parse_rgb(&r, &g, &b, line);
	if (r > 255 || g > 255 || b > 255
		|| r < 0 || g < 0 || b < 0)
	{
		ft_printf(ERR_FC_CUB);
		free(line);
		return (-1);
	}
	if (line[0] == 'F')
		FCOLOR = create_rgb(r, g, b);
	else if (line[0] == 'C')
		CCOLOR = create_rgb(r, g, b);
	return (0);
}

int	add_r_value(char *line, t_main *main_struct)
{
	if (check_r_value(line) == -1)
		return (-1);
	parse_res(line, main_struct);
	if (RES_X == 0 || RES_Y == 0)
	{
		ft_printf(ERR_R_SIZE);
		free(line);
		return (-1);
	}
	return (0);
}
