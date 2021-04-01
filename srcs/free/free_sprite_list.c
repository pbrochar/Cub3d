/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:16:47 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:27:15 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_sprite_list(t_main *main_struct)
{
	t_point *temp;

	while (SPRITE_LIST)
	{
		temp = SPRITE_LIST;
		SPRITE_LIST = SPRITE_LIST->next;
		free(temp);
	}
	return (0);
}
