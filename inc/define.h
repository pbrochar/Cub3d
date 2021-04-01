/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <pbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:57:36 by pbrochar          #+#    #+#             */
/*   Updated: 2021/04/01 18:20:58 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define LESS_ARGS "Error\nNeed .cub file.\n"
# define TOO_MANY_ARGS "Error\nToo many arguments.\n"
# define BAD_EXT "Error\nFirst argument need to be a .cub file.\n"
# define BAD_ARG "Error\nThe second argument can be --save.\n"
# define BAD_ACCESS_CUB "Error\nCan't access to %s.\n"
# define ERR_R_CUB "Error\nBad values for resolution.\n"
# define ERR_R_SIZE "Error\nResolution can't be 0.\n"
# define ERR_FC_CUB "Error\nBad values for color.\n"
# define ERR_INC_CUB "Error\nIncomplete .cub file. Need %s.\n"
# define ERR_INV_MAP "Error\nInvalid map.\n"
# define ERR_BMP_CREATE "Error\nCan't create .bmp file.\n"

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
