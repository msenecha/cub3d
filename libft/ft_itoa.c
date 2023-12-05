/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:17:13 by svidal            #+#    #+#             */
/*   Updated: 2023/02/15 15:21:06 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_numbers(int n)
{
	int	len;
	int	temp;

	temp = n;
	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

static char	*ft_allocate_string(int len)
{
	char	*str;

	str = ((char *)malloc(sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

static void	ft_fill_string(char *str, int len, int n)
{
	int	temp;

	if (n < 0)
		temp = -n;
	else
		temp = n;
	while (len--)
	{
		str[len] = temp % 10 + '0';
		temp /= 10;
	}
	if (n < 0)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_count_numbers(n);
	str = ft_allocate_string(len);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	ft_fill_string(str, len, n);
	return (str);
}
