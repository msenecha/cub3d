/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:45 by svidal            #+#    #+#             */
/*   Updated: 2023/02/15 17:40:11 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	if (!dest && size == 0)
		return (0);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (len_src + size);
	while (i < len_src && len_dest + i + 1 < size)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
