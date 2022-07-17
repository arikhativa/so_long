/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:59:33 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/17 10:46:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "object.h"

// TODO remove..
void	tab_print(char **tab)
{
	int	i;

	i = 0;
	while (NULL != tab[i])
	{
		printf("%s\n", tab[i]);
		++i;
	}
}

void	tab_free_lines(char **tab)
{
	int	i;

	i = 0;
	while (NULL != tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		++i;
	}
}

void	tab_free(char **tab)
{
	tab_free_lines(tab);
	free(tab);
}

void	tab_copy(char **d, char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		++i;
	}
	d[i] = NULL;
}

int	tab_count_char(char **tab, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		if (ft_strchr(tab[i], c))
			++count;
		++i;
	}
	return (count);
}
