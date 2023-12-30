/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:30:27 by svidal            #+#    #+#             */
/*   Updated: 2023/04/13 18:02:44 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_count_hexa(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_puthexa(unsigned int n, const char str)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, str);
		ft_puthexa(n % 16, str);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (str == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			if (str == 'X')
				ft_putchar_fd(n - 10 + 'A', 1);
		}
	}
}

int	ft_print_hexa(unsigned int n, const char str)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(n, str);
	return (ft_count_hexa(n));
}
