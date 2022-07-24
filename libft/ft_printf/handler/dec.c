/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:53:05 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "flag.h"
#include "generic.h"
#include "base.h"
#include "printable_mem.h"
#include "handler.h"

t_printable_mem	*handle_dec(va_list l, t_flag *f)
{
	int	nbr;

	nbr = va_arg(l, int);
	if (!should_print_zero((0 == nbr), f))
		return (create_empty_str(f));
	return (convert_generic_number(nbr, f, BASE_DEC_STR));
}
