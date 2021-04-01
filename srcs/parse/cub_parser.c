/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:35:21 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 15:55:59 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	replace_space_wall(t_main *main_struct)
{
	int i;
	int j;

	i = 0;
	while (i < Y_MAX)
	{
		j = 0;
		while (j < X_MAX)
		{
			if (MAP[i][j] == ' ')
				MAP[i][j] = '1';
			j++;
		}
		i++;
	}
}

int			parse_cub_file(char *cub_file, t_main *main_struct)
{
	int fd;

	if ((fd = open(cub_file, O_RDONLY)) == -1)
	{
		ft_printf(BAD_ACCESS_CUB, cub_file);
		return (-1);
	}
	if (parse_cub_info(fd, main_struct) == -1)
		return (-1);
	if (check_data(main_struct) == -1)
		return (-1);
	if (normalize_map(main_struct) == -1)
		return (-1);
	if (check_map(main_struct) == -1)
		return (-1);
	replace_space_wall(main_struct);
	return (0);
}

int			parse_cub_info(int fd, t_main *main_struct)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	if ((ret = get_next_line(fd, &line)) != 1)
		return (-1);
	i = line_skip_space(line);
	while (line_is_param(&line[i]) == 1 && ret != -1)
	{
		if (add_value_in_struct(line, i, main_struct) == -1)
			return (-1);
		free(line);
		ret = get_next_line(fd, &line);
		i = line_skip_space(line);
	}
	while (line_is_map(line) && ret != -1)
	{
		if (parse_cub_map(line, main_struct) == -1)
			return (-1);
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	return (0);
}

int			parse_cub_map(char *line, t_main *main_struct)
{
	char		**temp;
	int			i;

	Y_MAX++;
	i = 0;
	temp = malloc(sizeof(char *) * Y_MAX);
	if (temp == NULL)
		return (-1);
	while (i < Y_MAX - 1)
	{
		temp[i] = ft_strdup(MAP[i]);
		i++;
	}
	temp[i] = ft_strdup(line);
	free_map_for_realloc(main_struct);
	MAP = temp;
	return (0);
}

int			normalize_map(t_main *main_struct)
{
	char	*char_space;
	char	*temp;
	int		i;
	int		str_len;

	i = 0;
	get_x_max(main_struct);
	while (i < Y_MAX)
	{
		str_len = ft_strlen(MAP[i]);
		if (str_len < X_MAX)
		{
			temp = realloc_map_line(main_struct, MAP[i], str_len);
			char_space = get_char_space(main_struct, str_len);
			if (!temp || !char_space)
				return (-1);
			ft_strlcat(temp, char_space, X_MAX + 1);
			free(MAP[i]);
			free(char_space);
			MAP[i] = temp;
		}
		i++;
	}
	return (0);
}
