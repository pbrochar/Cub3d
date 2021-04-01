/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:49:20 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/21 15:21:47 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	parse_rgb(int *r, int *g, int *b, char *line)
{
	int i;

	i = 1;
	*r = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	*g = ft_atoi(&line[++i]);
	while (line[i] != ',')
		i++;
	*b = ft_atoi(&line[++i]);
}

void	parse_res(char *line, t_main *main_struct)
{
	int i;

	i = 1;
	while (!ft_isdigit(line[i]))
		i++;
	RES_X = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	RES_Y = ft_atoi(&line[i]);
}

void	parse_texture_path(char *line, t_main *main_struct)
{
	int i;

	if (ft_isalpha(line[1]))
		i = 2;
	else
		i = 1;
	while (ft_isspace(line[i]))
		i++;
	if (line[0] == 'N')
		NO_PATH = ft_strdup(&line[i]);
	if (line[0] == 'W')
		WE_PATH = ft_strdup(&line[i]);
	if (line[0] == 'E')
		EA_PATH = ft_strdup(&line[i]);
	if (line[0] == 'S')
	{
		if (line[1] == 'O')
			SO_PATH = ft_strdup(&line[i]);
		else
			SPRITE_PATH = ft_strdup(&line[i]);
	}
}
