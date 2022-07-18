/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hax_lower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:57:43 by yoav              #+#    #+#             */
/*   Updated: 2022/06/28 14:53:42 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "flag.h"
#include "define.h"
#include "generic.h"
#include "base.h"
#include "printable_mem.h"

t_printable_mem	*handle_hax_lower(va_list l, t_flag *f)
{
	unsigned int		nbr;

	nbr = va_arg(l, unsigned int);
	if (!should_print_zero((0 == nbr), f))
		return (create_empty_str(f));
	if (0 == nbr)
		f->hash = FALSE;
	return (convert_generic_unsigned_number(nbr, f, BASE_HAX_LOWER_STR));
}
