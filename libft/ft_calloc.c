/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:38:48 by svidal            #+#    #+#             */
/*   Updated: 2023/02/21 12:44:25 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb_elmts, size_t size)
{
	void	*ptr;
	size_t	temp;

	if (nb_elmts == 0 || size == 0)
		return (malloc(0));
	temp = (nb_elmts * size);
	if (temp / size != nb_elmts)
		return (NULL);
	ptr = (void *)malloc(nb_elmts * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nb_elmts * size);
	return (ptr);
}
