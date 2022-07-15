/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoav <yoav@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:35:18 by yoav              #+#    #+#             */
/*   Updated: 2022/06/29 11:18:17 by yoav             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4094
# endif

# ifndef MAX_FD
#  define MAX_FD 1000
# endif

# ifndef ERROR
#  define ERROR			-1
# endif

# define NL_CHAR		'\n'
# define END_OF_FILE	0

# include <stddef.h>

char	*ft_join_str(char *a, char *b);
size_t	ft_strlen(char *s);
void	ft_memcpy(char *d, char *s, size_t size);
void	swap_ptr(char **a, char **b);
char	*ft_strndup(char *s, size_t size);
char	*get_next_line(int fd);

#endif