/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:09:46 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/31 16:03:28 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# include "structs.h"
# include "define.h"
# include "libft.h"

/*
** from srcs/game_loop.c
*/
int					game_loop(t_main *main_struct);

/*
** from srcs/check/check.c
*/
int					check_data(t_main *main_struct);
int					check_fc_value(char *line);
int					check_map(t_main *main_struct);
int					check_r_value(char *line);

/*
** from srcs/check/check_map.c
*/
int					check_map_char(t_main *main_struct);
int					check_map_columns(t_main *main_struct);
int					check_map_rows(t_main *main_struct);
int					check_map_walls(t_main *main_struct);
int					skip_row_space(t_main *main_struct, int i, int j);

/*
** from srcs/check/check_map_utils.c
*/
int					manage_space_columns(t_main *main_struct, int i, int j);
int					manage_space_rows(t_main *main_struct, int i, int j);
int					manage_zero_two_columns(t_main *main_struct, int i, int j);
int					manage_zero_two_rows(t_main *main_struct, int i, int j);

/*
** from srcs/events/events.c
*/
int					events(t_main *main_struct);
int					destroy_window(t_main *main_struct);
int					key_pressed(int key, t_main *main_struct);
int					key_released(int key, t_main *main_struct);
void				init_move_struct(t_move *move, t_main *main_struct);

/*
** from srcs/events/events_move.c
*/
void				move_backward(t_main *main_struct);
void				move_forward(t_main *main_struct);
void				move_left(t_main *main_struct);
void				move_right(t_main *main_struct);

/*
** from srcs/events/events_rot.c
*/
void				rotate_left(t_main *main_struct);
void				rotate_right(t_main *main_struct);

/*
** from srcs/graphics/create_bmp.c
*/
int					create_bitmap(t_main *main_struct);

/*
** from srcs/graphics/draw.c
*/
int					draw_line(t_main *main_struct, int x);
int					get_pxl_color(t_data *img, int x, int y);
void				pxl_put(t_main *main_struct, int x, int y, int color);

/*
** from srcs/graphics/graphics_utils.c
*/
void				get_pos_start(t_main *main_struct);

/*
** from srcs/graphics/manage_sprite.c
*/
int					is_sprite(t_main *main_struct);
int					lst_to_tab(t_main *main_struct);
int					sort_sprite_tab(t_main *main_struct);

/*
** from srcs/graphics/raycasting.c
*/
int					raycasting(t_main *main_struct);

/*
** from srcs/graphics/sprite.c
*/
void				draw_sprite(t_main *main_struct);

/*
** from srcs/graphics/sprite_utils.c
*/
t_sprite_val		initial_sprite_calculation(t_main *main_struct, int i);
void				swap_point_tab(t_main *main_struct, int i, int j);

/*
** from srcs/graphics/textures.c
*/
int					*calcul_textures(t_main *main_struct, int i);

/*
** from srcs/init/free_sprite_list.c
*/
int					free_sprite_list(t_main *main_struct);

/*
** from srcs/init/free_struct.c
*/
void				free_map(t_main *main_struct);
void				free_struct(t_main *main_struct);

/*
** from srcs/init/init_graphics.c
*/
int					init_graphics(t_main *main_struct);

/*
** from srcs/init/init_raycasting.c
*/
void				init_raycasting(t_main *main_struct, int ray);

/*
** from srcs/init/init_struct.c
*/
int					init_struct(t_main **main_struct, int save_bmp);

/*
** from srcs/parse/add_param_struct.c
*/
int					add_fc_value(char *line, t_main *main_struct);
int					add_r_value(char *line, t_main *main_struct);
int					add_value_in_struct(char *line, int i, t_main *main_struct);

/*
** from srcs/parse/arg_parser.c
*/
int					check_args(int argc, char **argv, int *save_bmp);

/*
** from srcs/parse/cub_parser.c
*/
int					normalize_map(t_main *main_struct);
int					parse_cub_file(char *cub_file, t_main *main_struct);
int					parse_cub_info(int fd, t_main *main_struct);
int					parse_cub_map(char *line, t_main *main_struct);

/*
** from srcs/parse/map_utils.c
*/
char				*get_char_space(t_main *main_struct, int str_len);
char				*realloc_map_line(t_main *main_struct,
										char *map_line, int str_len);
void				free_map_for_realloc(t_main *main_struct);
void				get_x_max(t_main *main_struct);

/*
** from srcs/parse/parser_line_utils.c
*/
int					line_is_map(char *line);
int					line_is_param(char *line);
int					line_is_texture(char *line);
int					line_skip_space(char *line);

/*
** from srcs/parse/parser_utils.c
*/
int					create_rgb(int r, int g, int b);
void				parse_res(char *line, t_main *main_struct);
void				parse_rgb(int *r, int *g, int *b, char *line);
void				parse_texture_path(char *line, t_main *main_struct);

/*
** from srcs/utils/utils.c
*/
int					ft_charischar(int c, char *str);
int					ft_isspace(int c);

#endif
