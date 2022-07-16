/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:54:37 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 10:19:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// Bool Value
# define TRUE	1
# define FALSE	0

// Return Value
# define SUCCESS	0
# define ERROR		-1
# define EMPTY_FILE	-2
# define FD_ERROR	-3
# define OPEN_ERROR	-4
# define INVALID_MAP	-5

// Chars
# define VALID_CHARS	"01CEP"
# define NEW_LINE	'\n'
# define EMPTY_CHAR	'0'
# define WALL_CHAR	'1'
# define COLLECT_CHAR	'C'
# define ENEMY_CHAR	'E'
# define PLAYER_CHAR	'P'

// XPM
// General
# define XPM_PATH	"./resource/xpm/"
# define MAX_PATH	100
# define NUM_OF_SPRITES	2

// Images
# define WALL_I		0
# define WALL_STR	"wall.xpm"
# define BLOCK_I	1
# define BLOCK_STR	"block.xpm"

// Map
# define MIN_WIDTH_LEN	5
# define MIN_HEIGHT_LEN	5
# define BER_MAX_LINE	100
# define MAP_INVALIDE_X	-1

// Map Validate return value
# define BAD_CHAR_TOP	10
# define BAD_CHAR_MID	11
# define BAD_CHAR_BOTTOM	12

# define BAD_SIZE_TOP	20
# define BAD_SIZE_MID	21
# define BAD_SIZE_BOTTOM	22

# define BAD_HEIGHT	30


# ifndef WIDTH
#  define WIDTH		1980
# endif

# ifndef HEIGHT
#  define HEIGHT	1080
# endif

# ifndef NAME
#  define NAME		"so-long"
# endif

#endif
