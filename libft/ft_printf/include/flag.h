/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:14:33 by yoav              #+#    #+#             */
/*   Updated: 2022/06/22 11:20:32 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# include <stddef.h>

# define ALL_FLAGS	"-0# +"

typedef struct s_flag
{
	size_t	precision_value;
	int		width;
	char	is_precision;
	char	is_upper;
	char	hash;
	char	space;
	char	plus;
	char	left_adjusted;
	char	conversion;
	char	pad;
}	t_flag;

const char	*parse_flag(const char *s, t_flag *f);
const char	*get_flag(const char *s, t_flag *f);
const char	*skip_flag(const char *s);
int			is_handler_char(char c);
int			is_flag_valid(const char *s);

#endif
