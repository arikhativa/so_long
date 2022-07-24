/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:15:38 by yoav              #+#    #+#             */
/*   Updated: 2022/07/17 12:57:23 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*runner;

	if (!s)
		return (NULL);
	ch = (unsigned char)c;
	runner = (unsigned char *)s;
	while (n && *runner != ch)
	{
		++runner;
		--n;
	}
	if (!n)
		return (0);
	return (runner);
}
