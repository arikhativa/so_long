/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:54:37 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/24 11:13:56 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define GAME_NAME		"so-long"

// Bool Value
# define TRUE	1
# define FALSE	0

// Chars
# define VALID_CHARS	"01CEP"
# define NEW_LINE		'\n'
# define EMPTY_CHAR		'0'
# define WALL_CHAR		'1'
# define COLLECT_CHAR	'C'
# define EXIT_CHAR		'E'
# define PLAYER_CHAR	'P'
# define MIN_PLAYER		1
# define MIN_EXIT		1
# define MIN_COLLECT	1

// XPM
// General
# define XPM_PATH		"./resource/xpm/"
# define MAX_PATH		100
# define NUM_OF_SPRITES	5
# define IMG_SIZE		64

// Images
# define WALL_I			0
# define WALL_STR		"wall_01.xpm"
# define PLAYER_I		1
# define PLAYER_STR		"player_01.xpm"
# define EXIT_I			2
# define EXIT_STR		"door_01.xpm"
# define COLLECT_I		3
# define COLLECT_STR	"plant_01.xpm"
# define EMPTY_I		4
# define EMPTY_STR		"empty.xpm"

// Map
# define MIN_WIDTH_LEN		2
# define MIN_HEIGHT_LEN		2
# define BER_MAX_LINE		100
# define MAP_INVALID_X		-1
# define MOVE_COUNTER_TEXT	"Move Counter"
# define MOVE_COUNTER_COLOR	15921152
# define MOVE_COUNTER_X		2
# define END_MSG_I			7

// Events (defined by mlx)
# define DESTROY_WINDOW		17
# define ESC				53
# define KEY_UP				13
# define KEY_DOWN			1
# define KEY_LEFT			0
# define KEY_RIGHT			2

// Error Codes
// Return Value
# define SUCCESS				0
# define ERROR					-1
# define ERROR_FD				-3
# define ERROR_ARG				-6
# define ERROR_MAP_CREATE		99
# define ERROR_CHAR_TOP			10
# define ERROR_CHAR_MID			11
# define ERROR_CHAR_BOTTOM		12
# define ERROR_SIZE_TOP			20
# define ERROR_SIZE_MID			21
# define ERROR_SIZE_BOTTOM		22
# define ERROR_HEIGHT			30
# define ERROR_PLAYER			40
# define ERROR_COLLECT			41
# define ERROR_EXIT				42
# define ERROR_MLX_CONNECTION	100
# define ERROR_SPRITE_CREATE	101
# define ERROR_WINDOW_CREATE	102
# define ERROR_PLAYER_CREATE	103
# define ERROR_COLLECT_CREATE	104

#endif
