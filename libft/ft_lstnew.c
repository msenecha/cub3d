/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:34:52 by svidal            #+#    #+#             */
/*   Updated: 2023/02/16 15:38:46 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(sizeof(t_list));
	if (new_link == NULL)
		return (NULL);
	new_link->content = content;
	new_link->next = NULL;
	return (new_link);
}
