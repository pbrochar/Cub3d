/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:59:32 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 17:14:19 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_disp
{
	void	*mlx;
	void	*win;
	int		res_x;
	int		res_y;
}				t_disp;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct	s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	move_speed;
	double	rot_speed;
	double	*wall_dist_buf;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}				t_ray;

typedef struct	s_level
{
	char	**map;
	int		x_max;
	int		y_max;
	char	pos;
	int		fcolor;
	int		ccolor;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	char	*sprite;
}				t_level;

typedef struct	s_draw
{
	int line_height;
	int draw_start;
	int draw_end;
}				t_draw;

typedef	struct	s_tex
{
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		*color;
}				t_tex;

typedef struct	s_point
{
	int				x;
	int				y;
	struct s_point	*next;
}				t_point;

typedef struct	s_sprite
{
	int		nb_sprite;
	int		*sprite_order;
	int		*sprite_distance;
	int		actual_map_x;
	int		actual_map_y;
	t_point	*sprite_list;
	t_point	*sprite_tab;
}				t_sprite;

typedef struct	s_sprite_val
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_x;
	int		tex_y;
	int		stripe;
}				t_sprite_val;

typedef struct	s_move
{
	int forward;
	int	backward;
	int right;
	int left;
	int rotate_right;
	int rotate_left;
}				t_move;

typedef struct	s_main
{
	t_disp		*display;
	t_data		*data;
	t_data		*texture[5];
	t_ray		*ray;
	t_level		*level;
	t_draw		*draw;
	t_tex		*tex;
	t_sprite	*sprite;
	t_move		*move;
	int			save_bmp;
}				t_main;

#endif
