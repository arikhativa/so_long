/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/07/20 14:29:45 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "generic.h"
#include "define.h"
#include "base.h"
#include "printable_mem.h"
#include "handler.h"
#include "convert.h"

t_printable_mem	*handle_ptr(va_list l, t_flag *f)
{
	void	*p;

	p = va_arg(l, void *);
	f->hash = TRUE;
	return (convert_generic_unsigned_number((size_t)p, f, BASE_HAX_LOWER_STR));
}
