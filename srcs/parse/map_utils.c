/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:55:18 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:19:44 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_x_max(t_main *main_struct)
{
	int	str_len;
	int i;

	i = 0;
	while (i < main_struct->level->y_max)
	{
		str_len = ft_strlen(main_struct->level->map[i]);
		if (str_len > main_struct->level->x_max)
			main_struct->level->x_max = str_len;
		i++;
	}
}

char	*get_char_space(t_main *main_struct, int str_len)
{
	char	*char_space;
	int		len;
	int		i;

	i = 0;
	len = (main_struct->level->x_max - str_len);
	char_space = malloc(sizeof(char) * (len + 1));
	if (!char_space)
		return (NULL);
	char_space[0] = '\0';
	while (i < len)
	{
		char_space[i] = ' ';
		i++;
	}
	char_space[i] = '\0';
	return (char_space);
}

char	*realloc_map_line(t_main *main_struct, char *map_line, int str_len)
{
	char *temp;

	temp = malloc(sizeof(char) * (main_struct->level->x_max + 1));
	if (!temp)
		return (NULL);
	ft_memset(temp, '\0', main_struct->level->x_max);
	temp = ft_memcpy(temp, map_line, str_len);
	return (temp);
}

void	free_map_for_realloc(t_main *main_struct)
{
	int i;

	i = 0;
	while (i < main_struct->level->y_max - 1)
	{
		free(main_struct->level->map[i]);
		i++;
	}
	free(main_struct->level->map);
}
