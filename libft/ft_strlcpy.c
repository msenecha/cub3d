/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:41:04 by svidal            #+#    #+#             */
/*   Updated: 2023/02/14 16:08:00 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	n;

	src_len = ft_strlen(src);
	n = 0;
	if (size > 0)
	{
		while (n < size - 1 && src[n] != '\0')
		{
		dest[n] = src[n];
		n++;
		}
	dest[n] = '\0';
	}
	return (src_len);
}
