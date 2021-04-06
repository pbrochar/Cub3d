/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:51:03 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/06 15:52:59 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_data_addr(t_main *main_struct, int i)
{
		main_struct->texture[i]->addr =
		mlx_get_data_addr(main_struct->texture[i]->img,
										&main_struct->texture[i]->bpp,
		&main_struct->texture[i]->line_length,
									&main_struct->texture[i]->endian);
}