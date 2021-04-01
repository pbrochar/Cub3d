/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:34:15 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:26:17 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_param(const char *param, const char *ref)
{
	int param_len;
	int	ref_len;

	param_len = ft_strlen(param);
	ref_len = ft_strlen(ref);
	if (param_len != ref_len)
		return (-1);
	if (ft_strncmp(param, ref, param_len) != 0)
		return (-1);
	return (0);
}

static int	check_ext(const char *file_name, const char *ext)
{
	int		i;
	size_t	file_name_len;

	i = 0;
	file_name_len = ft_strlen(file_name);
	while (file_name[i] && file_name[i] != '.')
		i++;
	if (file_name[i])
	{
		if (ft_strncmp(&file_name[i], ext, (size_t)file_name - i) == 0)
			return (0);
	}
	return (-1);
}

static int	init_save_param(char **argv, int *save_bmp)
{
	if (check_param(argv[2], "--save") == -1)
	{
		ft_printf(BAD_ARG);
		return (-1);
	}
	else
		*save_bmp = 1;
	return (0);
}

int			check_args(int argc, char **argv, int *save_bmp)
{
	int ret;

	if (argc < 2 || argc > 3)
	{
		if (argc < 2)
			ft_printf(LESS_ARGS);
		else if (argc > 4)
			ft_printf(TOO_MANY_ARGS);
		return (-1);
	}
	if (check_ext(argv[1], ".cub") == -1)
	{
		ft_printf(BAD_EXT);
		return (-1);
	}
	if (argc == 3)
		if (init_save_param(argv, save_bmp) == -1)
			return (-1);
	return (0);
}
