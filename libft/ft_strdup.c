/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:33:23 by svidal            #+#    #+#             */
/*   Updated: 2023/02/08 18:36:59 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(str) + 1;
	cpy = malloc(len);
	if (cpy == NULL)
		return (NULL);
	return (ft_memcpy(cpy, str, len));
}
