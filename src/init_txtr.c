/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:23:39 by svidal            #+#    #+#             */
/*   Updated: 2023/12/21 16:05:33 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_xpm_to_tab(t_general *gen, char *path)
{
	t_img	tmp;
	int		*tab;
	int		x;
	int		y;

	init_texture_img(gen, &tmp, path);
	tab = (int *)malloc(sizeof(*tab) * gen->txtr_ptr.size * gen->txtr_ptr.size)
	y = 0;
	while (y < gen->txtr_ptr.size)
	{
		x = 0;
		while (x < gen->txtr_ptr.size)
		{
			tab[y * gen->txtr_ptr.size + x] = tmp.addr[y * gen->txtr_ptr.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(gen->mlx_ptr, tmp.main_img);
	return (tab);
}

void	ft_init_txtr(t_general *gen)
{
	gen->txtr = (int **)malloc(5 * sizeof(int *));
	gen->txtr[NORTH] = ft_xpm_to_tab(gen, gen->txtr_ptr.north);
	gen->txtr[SOUTH] = ft_xpm_to_tab(gen, gen->txtr_ptr.south);
	gen->txtr[EAST] = ft_xpm_to_tab(gen, gen->txtr_ptr.east);
	gen->txtr[WEST] = ft_xpm_to_tab(gen, gen->txtr_ptr.west);
}
