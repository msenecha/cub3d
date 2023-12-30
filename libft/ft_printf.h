/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:16:05 by svidal            #+#    #+#             */
/*   Updated: 2023/04/13 18:54:58 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_percent(void);
int		ft_print_int(int n);
int		ft_print_unsigned_int(unsigned int n);
int		ft_print_hexa(unsigned int n, const char str);
int		ft_print_ptr(unsigned long long ptr);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa_unsigned(unsigned int n);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
