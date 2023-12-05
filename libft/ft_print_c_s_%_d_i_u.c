/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_s_%_d_i_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:28:29 by svidal            #+#    #+#             */
/*   Updated: 2023/04/18 18:22:07 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_int(int n)
{
	int		len;
	char	*nb;

	len = 0;
	nb = ft_itoa(n);
	len = ft_print_str(nb);
	free(nb);
	return (len);
}

int	ft_print_unsigned_int(unsigned int n)
{
	unsigned int	len;
	char			*nb;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		nb = ft_itoa_unsigned(n);
		len = ft_print_str(nb);
		free(nb);
	}
	return (len);
}
