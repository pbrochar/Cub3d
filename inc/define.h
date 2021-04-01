/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:57:36 by pbrochar          #+#    #+#             */
/*   Updated: 2021/03/30 20:59:02 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define LESS_ARGS "Error\nNeed .cub file.\n"
# define TOO_MANY_ARGS "Error\nToo many arguments.\n"
# define BAD_EXT "Error\nFirst argument need to be a .cub file.\n"
# define BAD_ARG "Error\nThe second argument can be \
--save to save an image in .bmp format.\n"
# define BAD_ACCESS_CUB "Error\nCan't access to %s.\n"
# define ERR_R_CUB "Error\nBad values for resolution.\n"
# define ERR_R_SIZE "Error\nResolution can't be 0.\n"
# define ERR_FC_CUB "Error\nBad values for color.\n"
# define ERR_INC_CUB "Error\nIncomplete .cub file. Need %s.\n"
# define ERR_INV_MAP "Error\nInvalid map.\n"
# define ERR_BMP_CREATE "Error\nCan't create .bmp file.\n"

# define RES_X main_struct->display->res_x
# define RES_Y main_struct->display->res_y

# define FCOLOR main_struct->level->fcolor
# define CCOLOR main_struct->level->ccolor

# define NO_PATH main_struct->level->n_texture
# define SO_PATH main_struct->level->s_texture
# define WE_PATH main_struct->level->w_texture
# define EA_PATH main_struct->level->e_texture
# define SPRITE_PATH main_struct->level->sprite

# define MAP main_struct->level->map
# define X_MAX main_struct->level->x_max
# define Y_MAX main_struct->level->y_max

# define MLX main_struct->display->mlx
# define WIN main_struct->display->win
# define IMG main_struct->data->img

# define POSX main_struct->ray->pos_x
# define POSY main_struct->ray->pos_y
# define DIRX main_struct->ray->dir_x
# define DIRY main_struct->ray->dir_y
# define PLANEX main_struct->ray->plane_x
# define PLANEY main_struct->ray->plane_y
# define MAPX main_struct->ray->map_x
# define MAPY main_struct->ray->map_y
# define CAMERA_X main_struct->ray->camera_x
# define SIDE_DIST_X main_struct->ray->side_dist_x
# define SIDE_DIST_Y main_struct->ray->side_dist_y
# define DELTA_DIST_X main_struct->ray->delta_dist_x
# define DELTA_DIST_Y main_struct->ray->delta_dist_y
# define RAY_DIR_X main_struct->ray->ray_dir_x
# define RAY_DIR_Y main_struct->ray->ray_dir_y
# define PERP_W_DIST main_struct->ray->perp_wall_dist
# define STEP_X main_struct->ray->step_x
# define STEP_Y main_struct->ray->step_y
# define HIT main_struct->ray->hit
# define SIDE main_struct->ray->side
# define WALL_DIST_BUF main_struct->ray->wall_dist_buf

# define ADDR main_struct->data->addr
# define BPP main_struct->data->bits_per_pixel
# define LINE_LENGTH main_struct->data->line_length
# define ENDIAN main_struct->data->endian
# define MOVE_SPEED main_struct->ray->move_speed
# define ROT_SPEED main_struct->ray->rot_speed

# define TEXTURES main_struct->texture

# define DRAW_START main_struct->draw->draw_start
# define DRAW_END main_struct->draw->draw_end
# define DRAW_LINE_HEIGHT main_struct->draw->line_height

# define WALL_X main_struct->tex->wall_x
# define STEP main_struct->tex->step
# define TEX_POS main_struct->tex->tex_pos
# define TEX_X main_struct->tex->tex_x
# define TEX_Y main_struct->tex->tex_y
# define COLOR_TAB main_struct->tex->color

# define ACTUAL_MAPX main_struct->sprite->actual_map_x
# define ACTUAL_MAPY main_struct->sprite->actual_map_y
# define SPRITE_LIST main_struct->sprite->sprite_list
# define SPRITE_TAB main_struct->sprite->sprite_tab
# define NB_SPRITE main_struct->sprite->nb_sprite

# define KEY_FORWARD 119
# define KEY_BACKWARD 115
# define KEY_RIGHT_SIDE 100
# define KEY_LEFT_SIDE 97
# define KEY_CAM_RIGHT 65363
# define KEY_CAM_LEFT 65361
# define KEY_ESC 0xFF1b

# define CONST_ROT_SPEED 0.10
# define CONST_MOVE_SPEED 0.15
#endif
