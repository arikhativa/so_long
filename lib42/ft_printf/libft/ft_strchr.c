/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:20:44 by yoav              #+#    #+#             */
/*   Updated: 2022/07/17 12:57:29 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*runner;
	char	ch;

	if (!s)
		return (0);
	ch = (char)c;
	runner = (char *)s;
	while (*runner && *runner != ch)
		++runner;
	if (ch && !*runner)
		return ((char *)0);
	return (runner);
}
