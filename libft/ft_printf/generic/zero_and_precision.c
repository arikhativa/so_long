/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_and_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:44:54 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:53:13 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "printable_mem.h"
#include "flag.h"
#include "handler.h"

int	should_print_zero(int is_zero, t_flag *f)
{
	return (!(is_zero && f->is_precision && 0 == f->precision_value));
}

t_printable_mem	*create_empty_str(t_flag *f)
{
	return (create_str_to_print(EMPTY_STR, f, ft_strlen(EMPTY_STR)));
}
