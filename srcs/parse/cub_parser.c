/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:35:21 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:18:46 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	replace_space_wall(t_main *main_struct)
{
	int i;
	int j;

	i = 0;
	while (i < main_struct->level->y_max)
	{
		j = 0;
		while (j < main_struct->level->x_max)
		{
			if (main_struct->level->map[i][j] == ' ')
				main_struct->level->map[i][j] = '1';
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

	main_struct->level->y_max++;
	i = 0;
	temp = malloc(sizeof(char *) * main_struct->level->y_max);
	if (temp == NULL)
		return (-1);
	while (i < main_struct->level->y_max - 1)
	{
		temp[i] = ft_strdup(main_struct->level->map[i]);
		i++;
	}
	temp[i] = ft_strdup(line);
	free_map_for_realloc(main_struct);
	main_struct->level->map = temp;
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
	while (i < main_struct->level->y_max)
	{
		str_len = ft_strlen(main_struct->level->map[i]);
		if (str_len < main_struct->level->x_max)
		{
			temp = realloc_map_line(main_struct,
							main_struct->level->map[i], str_len);
			char_space = get_char_space(main_struct, str_len);
			if (!temp || !char_space)
				return (-1);
			ft_strlcat(temp, char_space, main_struct->level->x_max + 1);
			free(main_struct->level->map[i]);
			free(char_space);
			main_struct->level->map[i] = temp;
		}
		i++;
	}
	return (0);
}
