/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:38:35 by svidal            #+#    #+#             */
/*   Updated: 2023/12/13 22:37:10 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_s_map(t_map *map_ptr)
{
	map_ptr->map = NULL;
	map_ptr->map_cpy = NULL;
	map_ptr->data = NULL;
	map_ptr->path = NULL;
	map_ptr->map_width = 0;
	map_ptr->map_height = 0;
	map_ptr->nb_lines = 0;
	map_ptr->map_lines = 0;
	map_ptr->data_lines = 0;
	map_ptr->nb_columns = 0;
}

void	ft_init_s_img(t_img *img)
{
	//img->main_img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	ft_init_s_pst(t_pst *pst_ptr)
{
	pst_ptr->first_pst_x = 0.0;
	pst_ptr->first_pst_y = 0.0;
}

void	ft_init_s_player(t_player *player_ptr)
{
	player_ptr->dir = NULL;
	player_ptr->pst_x = 0.0;
	player_ptr->pst_y = 0.0;
	player_ptr->dir_x = 0.0;
	player_ptr->dir_y = 0.0;
	player_ptr->wall_dist = 0.0;
	player_ptr->plan_x = 0.0;
	player_ptr->plan_y = 0.0;
	player_ptr->has_moved = 0;
	player_ptr->move_x = 0;
	player_ptr->move_y = 0;
	player_ptr->rotate = 0;
	player_ptr->nb_player = 0;
}
