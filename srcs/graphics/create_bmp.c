/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:33:31 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 17:25:42 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel_bmp(t_main *main_struct, int fd, int x, int y)
{
	int color;
	int r;
	int g;
	int b;

	color = get_pxl_color(main_struct->data, x, y);
	b = color & 0xff;
	g = (color >> 8) & 0xff;
	r = (color >> 16) & 0xff;
	write(fd, &b, 1);
	write(fd, &g, 1);
	write(fd, &r, 1);
	write(fd, "\0", 1);
}

static int	fill_bitmap(t_main *main_struct, int fd)
{
	int x;
	int y;

	y = RES_Y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < RES_X)
		{
			put_pixel_bmp(main_struct, fd, x, y);
			x++;
		}
		y--;
	}
	return (0);
}

static void	header_bitmap(t_main *main_struct, int fd)
{
	int header_size;
	int	nb_plan;
	int image_size;

	header_size = 40;
	nb_plan = 1;
	image_size = RES_Y * RES_X;
	write(fd, &header_size, 4);
	write(fd, &RES_X, 4);
	write(fd, &RES_Y, 4);
	write(fd, &nb_plan, 2);
	write(fd, &BPP, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

int			create_bitmap(t_main *main_struct)
{
	int fd;
	int file_size;
	int	offset;

	fd = open("cub3D.bmp", O_CREAT | O_RDWR, 0777);
	if (fd == -1)
	{
		ft_printf(ERR_BMP_CREATE);
		return (-1);
	}
	offset = 54;
	file_size = offset + RES_X * RES_Y * 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
	header_bitmap(main_struct, fd);
	fill_bitmap(main_struct, fd);
	main_struct->save_bmp = 0;
	return (0);
}
