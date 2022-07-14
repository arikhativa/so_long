/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:54:37 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/14 18:54:35 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SUCCESS	0
# define ERROR		-1
# define XPM_PATH	"./resource/xpm/"
# define MAX_PATH	100
# define NUM_OF_SPRITES	2

# define WALL_I		0
# define WALL_STR	"wall.xpm"

# define BLOCK_I	1
# define BLOCK_STR	"block.xpm"

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
