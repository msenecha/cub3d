/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:27:09 by svidal            #+#    #+#             */
/*   Updated: 2023/02/07 11:47:11 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*ptr1;
	char		*ptr2;

	ptr1 = (const char *)src;
	ptr2 = (char *)dest;
	while (n--)
		*ptr2++ = *ptr1++;
	return (dest);
}
