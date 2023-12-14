/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:36:15 by svidal            #+#    #+#             */
/*   Updated: 2023/12/13 20:15:56 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	printf("\n");
}
