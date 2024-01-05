/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_txtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:02 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/21 16:40:42 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	*xpm_to_img(t_general *gen, char *path)
{
	t_img	*tmp;
	int		*buffer;
	int		x;
	int		y;

	printf("PATH = %s\n", path);
    tmp = &gen->img_ptr;
    init_texture_img(gen, tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * gen->txtr_ptr.size * gen->txtr_ptr.size);
	if (!buffer)
		ft_error_msg("Error: cannot convert xpm to image\n", gen);
	y = 0;
	while (y < gen->txtr_ptr.size)
	{
		x = 0;
		while (x < gen->txtr_ptr.size)
		{
			buffer[y * gen->txtr_ptr.size + x]
				= tmp->addr[y * gen->txtr_ptr.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(gen->mlx_ptr, tmp->main_img);
	return (buffer);
}

void	init_textures(t_general *gen)
{
	gen->txtr = ft_calloc(5, sizeof * gen->txtr);
	if (!gen->txtr)
		ft_error_msg("Error: cannot convert xpm to image\n", gen);
	gen->txtr[NORTH] = xpm_to_img(gen, gen->txtr_ptr.north);
	gen->txtr[SOUTH] = xpm_to_img(gen, gen->txtr_ptr.south);
	gen->txtr[EAST] = xpm_to_img(gen, gen->txtr_ptr.east);
	gen->txtr[WEST] = xpm_to_img(gen, gen->txtr_ptr.west);
}