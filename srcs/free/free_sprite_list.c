/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:16:47 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:05:46 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_sprite_list(t_main *main_struct)
{
	t_point *temp;

	while (main_struct->sprite->sprite_list)
	{
		temp = main_struct->sprite->sprite_list;
		main_struct->sprite->sprite_list =
							main_struct->sprite->sprite_list->next;
		free(temp);
	}
	return (0);
}
