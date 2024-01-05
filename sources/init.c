/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:17:03 by svidal            #+#    #+#             */
/*   Updated: 2024/01/05 15:15:02 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_init_img(t_image *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	ft_init_ray(t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
}

static void	ft_init_map_infos(t_mapinfo *mapinfo)
{
	mapinfo->fd = 0;
	mapinfo->line_count = 0;
	mapinfo->path = NULL;
	mapinfo->file = NULL;
	mapinfo->height = 0;
	mapinfo->width = 0;
	mapinfo->index_end_of_map = 0;
}

static void	ft_init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	ft_init_player(&data->player);
	ft_init_txtr_inf(&data->texinfo);
	data->map = NULL;
	ft_init_map_infos(&data->mapinfo);
	data->texture_pixels = NULL;
	data->textures = NULL;
}
