/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtr_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:02:26 by svidal            #+#    #+#             */
/*   Updated: 2024/01/04 16:52:57 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	*ft_convert_xpm(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	ft_init_txtr_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * data->texinfo.size * data->texinfo.size);
	if (!buffer)
		ft_exit(data, error_msg(NULL, "Error: m/calloc failed!\n", 1));
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			buffer[y * data->texinfo.size + x]
				= tmp.addr[y * data->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	ft_init_txtr(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		ft_exit(data, error_msg(NULL, "Error: m/calloc failed!\n", 1));
	data->textures[NORTH] = ft_convert_xpm(data, data->texinfo.north);
	data->textures[SOUTH] = ft_convert_xpm(data, data->texinfo.south);
	data->textures[EAST] = ft_convert_xpm(data, data->texinfo.east);
	data->textures[WEST] = ft_convert_xpm(data, data->texinfo.west);
}

void	ft_init_txtr_inf(t_texture *textures)
{
	textures->north = NULL;
	textures->south = NULL;
	textures->west = NULL;
	textures->east = NULL;
	textures->floor = 0;
	textures->ceiling = 0;
	textures->hex_floor = 0x0;
	textures->hex_ceiling = 0x0;
	textures->size = TEX_SIZE;
	textures->step = 0.0;
	textures->pos = 0.0;
	textures->x = 0;
	textures->y = 0;
}
