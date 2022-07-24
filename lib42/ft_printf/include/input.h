/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:47:03 by yoav              #+#    #+#             */
/*   Updated: 2022/06/21 09:24:14 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdarg.h>

# include "libft.h"

int			is_escp(const char *s);
const char	*skip_escp(const char *s);
int			is_flag(const char *s);
int			parse_input(const char *input, t_list **node, va_list list);
size_t		count_normal_char_len(const char *s);

#endif
