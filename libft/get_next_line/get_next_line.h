/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:35:18 by yoav              #+#    #+#             */
/*   Updated: 2022/07/24 11:29:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef MAX_FD
#  define MAX_FD 10
# endif

# ifndef ERROR
#  define ERROR			-1
# endif

# define NL_CHAR		'\n'
# define END_OF_FILE	0

# include <stddef.h>

char	*gnl_join_str(char *a, char *b);
size_t	gnl_strlen(char *s);
void	gnl_swap_ptr(char **a, char **b);
char	*gnl_strndup(char *s, size_t size);
char	*get_next_line(int fd);

#endif
