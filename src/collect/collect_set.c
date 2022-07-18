/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:36:56 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/18 15:01:06 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"


#include <execinfo.h>
#include <stdlib.h>
#include <stdio.h>

void	collect_decries(t_meta *m)
{
	void* callstack[128];

	int i, frames = backtrace(callstack, 128);
	char** strs = backtrace_symbols(callstack, frames);
	for (i = 0; i < frames; ++i) {
    	printf("%s\n", strs[i]);
	}
	free(strs);
	--m->collect->num_of_collect;
}

void	collect_set(t_meta *m, int collect)
{
	m->collect->num_of_collect = collect;
}
