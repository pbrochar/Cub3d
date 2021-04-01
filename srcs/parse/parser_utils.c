/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:49:20 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 16:54:28 by pbrochar         ###   ########.fr       */
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
	main_struct->display->res_x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	main_struct->display->res_y = ft_atoi(&line[i]);
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
		main_struct->level->n_texture = ft_strdup(&line[i]);
	if (line[0] == 'W')
		main_struct->level->w_texture = ft_strdup(&line[i]);
	if (line[0] == 'E')
		main_struct->level->e_texture = ft_strdup(&line[i]);
	if (line[0] == 'S')
	{
		if (line[1] == 'O')
			main_struct->level->s_texture = ft_strdup(&line[i]);
		else
			main_struct->level->sprite = ft_strdup(&line[i]);
	}
}
