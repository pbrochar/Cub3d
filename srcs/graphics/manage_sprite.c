/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:20:41 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/29 18:22:05 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double		calculate_distance_sprite(t_main *main_struct, int index)
{
	double dist;

	dist = ((POSX - SPRITE_TAB[index].x)
			* (POSX - SPRITE_TAB[index].x)
			+ (POSY - SPRITE_TAB[index].y)
			* (POSY - SPRITE_TAB[index].y));
	return (dist);
}

int					sort_sprite_tab(t_main *main_struct)
{
	int		i;
	int		j;
	double	dist_one;
	double	dist_two;

	i = 0;
	while (i < NB_SPRITE)
	{
		j = i + 1;
		dist_one = calculate_distance_sprite(main_struct, i);
		while (j < NB_SPRITE)
		{
			dist_two = calculate_distance_sprite(main_struct, j);
			if (dist_two < dist_one)
				swap_point_tab(main_struct, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int					lst_to_tab(t_main *main_struct)
{
	t_point *sprite_tab;
	int		i;
	int		size;

	size = ft_lstsize((t_list *)SPRITE_LIST);
	i = 0;
	sprite_tab = malloc(sizeof(t_point) * size);
	if (!sprite_tab)
		return (-1);
	ft_bzero(sprite_tab, size);
	while (i < size)
	{
		sprite_tab[i].x = SPRITE_LIST->x;
		sprite_tab[i].y = SPRITE_LIST->y;
		SPRITE_LIST = SPRITE_LIST->next;
		i++;
	}
	main_struct->sprite->sprite_tab = sprite_tab;
	return (0);
}

static int			check_duplicate_sprite(t_main *main_struct)
{
	t_point	*temp;

	temp = SPRITE_LIST;
	if (temp != NULL)
	{
		while (temp)
		{
			if (temp->x == MAPX && temp->y == MAPY)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}

int					is_sprite(t_main *main_struct)
{
	t_point	*new_sprite;
	t_point	*temp;

	if (check_duplicate_sprite(main_struct) == 1)
		return (0);
	new_sprite = malloc(sizeof(t_point));
	if (!new_sprite)
		return (-1);
	new_sprite->next = NULL;
	new_sprite->x = MAPX;
	new_sprite->y = MAPY;
	NB_SPRITE++;
	if (SPRITE_LIST == NULL)
		SPRITE_LIST = new_sprite;
	else
	{
		temp = SPRITE_LIST;
		while (temp->next)
			temp = temp->next;
		temp->next = new_sprite;
	}
	return (0);
}
