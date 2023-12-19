/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:36:15 by svidal            #+#    #+#             */
/*   Updated: 2023/12/19 12:19:25 by svidal           ###   ########.fr       */
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
