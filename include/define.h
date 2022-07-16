/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:54:37 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/16 18:19:53 by yrabby           ###   ########.fr       */
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
# define EXIT_CHAR	'E'
# define PLAYER_CHAR	'P'
# define MIN_PLAYER	1
# define MIN_EXIT	1
# define MIN_COLLECT	1

// XPM
// General
# define XPM_PATH	"./resource/xpm/"
# define MAX_PATH	100
# define NUM_OF_SPRITES	5
# define IMG_SIZE	64

// Images
# define WALL_I		0
# define WALL_STR	"wall_01.xpm"
# define PLAYER_I	1
# define PLAYER_STR	"player_01.xpm"
# define EXIT_I		2
# define EXIT_STR	"door_01.xpm"
# define COLLECT_I	3
# define COLLECT_STR	"plant_01.xpm"
# define EMPTY_I	4
# define EMPTY_STR	"empty.xpm"

// Map
# define MIN_WIDTH_LEN	2
# define MIN_HEIGHT_LEN	2
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

# define BAD_PLAYER	40
# define BAD_COLLECT	41
# define BAD_EXIT	42

// Events (defined my mlx)
# define KEY_PRESS	2
# define DESTORY_WINDOW	17
# define ESC	53
# define RESET	15
# define KEY_UP		13
# define KEY_DOWN	 1
# define KEY_LEFT	 0
# define KEY_RIGHT	 2

# define GAME_NAME		"so-long"

#endif
