/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:14:20 by svidal            #+#    #+#             */
/*   Updated: 2023/02/07 11:31:22 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr1;
	unsigned char		*ptr2;

	ptr1 = (const unsigned char *)src;
	ptr2 = (unsigned char *)dest;
	if (ptr2 < ptr1)
	{
		while (n--)
			*ptr2++ = *ptr1++;
	}
	else if (ptr2 > ptr1)
	{
		while (n--)
			ptr2[n] = ptr1[n];
	}
	else
		return (dest);
	return (dest);
}
