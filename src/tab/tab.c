/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:59:33 by yrabby            #+#    #+#             */
/*   Updated: 2022/07/15 15:25:17 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

// TODO remove?
// char	**tab_create(t_point *size)
// {
// 	char	**tab;
// 	int		i;

// 	tab = (char **)malloc(sizeof(char *) * (size->y + 1));
// 	if (!tab)
// 		return (NULL);
// 	i = 0;
// 	while (i < size->y)
// 	{
// 		tab[i] = (char *)malloc(sizeof(char) * (size->x + 1));
// 		if (!(tab[i]))
// 		{
// 			tab_free(tab);
// 			return (NULL);
// 		}
// 		++i;
// 	}
// 	tab[i] = NULL;
// }
