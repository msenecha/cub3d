/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:38:11 by svidal            #+#    #+#             */
/*   Updated: 2023/12/05 18:00:27 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_map(char **tab, t_general *general)
{
	int	i;

	i = 0;
	while (i < general->map_ptr.nb_lines)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	ft_free_img(t_general *general)
{
	//mlx_destroy_image(general->mlx_ptr, general->img_ptr.floor);
	//mlx_destroy_image(general->mlx_ptr, general->img_ptr.wall);
	general->img_ptr = (t_img){0}; //permet de reinitialiser ts les elmts de la struct a 0
}

int	ft_exit_game(t_general *general)
{
	ft_free_img(general);
	ft_free_map(general->map_ptr.map, general);
	mlx_destroy_window(general->mlx_ptr, general->win_ptr);
	mlx_destroy_display(general->mlx_ptr);
	free(general->mlx_ptr);
	free(general);
	exit (0);
}
