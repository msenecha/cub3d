/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:56:54 by svidal            #+#    #+#             */
/*   Updated: 2023/02/15 15:48:09 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n-- && (*str1 || *str2))
	{
		if (*str1++ != *str2++)
			return (*(unsigned char *)(str1 - 1) -
			*(unsigned char *)(str2 - 1));
	}
	return (0);
}
