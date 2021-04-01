/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:00:54 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/21 12:23:56 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		line_is_texture(char *line)
{
	int			i;
	static char	*keyword[5] = {"NO", "SO", "WE", "EA", "S "};

	i = 0;
	while (i < 5)
	{
		if (ft_strncmp(line, keyword[i], 2) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		line_is_map(char *line)
{
	static char map_char[3] = {'0', '1', ' '};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (line[0] == map_char[i])
			return (1);
		i++;
	}
	return (0);
}

int		line_is_param(char *line)
{
	static char param[7] = {'R', 'F', 'C', 'N', 'S', 'W', 'E'};
	int			i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (i < 7)
	{
		if (line[0] == param[i])
			return (1);
		i++;
	}
	return (0);
}

int		line_skip_space(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]) == 1)
		i++;
	return (i);
}
