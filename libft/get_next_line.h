/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:22:38 by svidal            #+#    #+#             */
/*   Updated: 2023/03/13 17:58:14 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_reading(int fd, char *storage);
char	*ft_get_line(char *storage);
char	*ft_extract_rest(char *storage);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
ssize_t	read(int fd, void *buf, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
