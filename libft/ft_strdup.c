/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:33:23 by svidal            #+#    #+#             */
/*   Updated: 2023/12/06 18:13:23 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*cpy;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	cpy = malloc(len);
	if (cpy == NULL)
		return (NULL);
	return (ft_memcpy(cpy, str, len));
}
