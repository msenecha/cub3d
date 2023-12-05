/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:16:22 by svidal            #+#    #+#             */
/*   Updated: 2023/04/19 10:25:10 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_char(va_list argmts, char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_print_char(va_arg(argmts, int));
	else if (str == 's')
		len += ft_print_str(va_arg(argmts, char *));
	else if (str == '%')
		len += ft_print_percent();
	else if (str == 'd' || str == 'i')
		len += ft_print_int(va_arg(argmts, int));
	else if (str == 'u')
		len += ft_print_unsigned_int(va_arg(argmts, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_print_hexa(va_arg(argmts, unsigned int), str);
	else if (str == 'p')
		len += ft_print_ptr(va_arg(argmts, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	argmts;

	if (!str)
		return (-1);
	va_start(argmts, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_check_char(argmts, str[i + 1]);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(argmts);
	return (len);
}
