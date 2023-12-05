/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:04:41 by svidal            #+#    #+#             */
/*   Updated: 2023/04/14 19:16:42 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_numbers(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_allocate_string(unsigned int len)
{
	char	*str;

	str = ((char *)malloc(sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

void	ft_fill_string(char *str, unsigned int len, unsigned int n)
{
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa_unsigned(unsigned int n)
{
	unsigned int	len;
	char			*str;

	len = ft_count_numbers(n);
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	str = ft_allocate_string(len);
	if (!str)
		return (NULL);
	ft_fill_string(str, len, n);
	return (str);
}
