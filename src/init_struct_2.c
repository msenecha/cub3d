/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:38:45 by svidal            #+#    #+#             */
/*   Updated: 2023/12/14 10:23:17 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_s_txtr(t_txtr *txtr_ptr)
{
	txtr_ptr->north = NULL;
	txtr_ptr->south = NULL;
	txtr_ptr->east = NULL;
	txtr_ptr->west = NULL;
	txtr_ptr->floor = 0;
	txtr_ptr->wall = 0;
	txtr_ptr->size = 0;
	txtr_ptr->tex_x = 0;
	txtr_ptr->tex_y = 0;
}
//other init to be done for textures

//voir ou on l'appelle celle la
void	ft_init_s_ray(t_ray *ray_ptr)
{
	ray_ptr->xxx = 0;
	ray_ptr->map_x = 0;
	ray_ptr->map_y = 0;
	ray_ptr->step_x = 0;
	ray_ptr->step_y = 0;
	ray_ptr->side = 0;
	ray_ptr->line_height = 0;
	ray_ptr->draw_start = 0;
	ray_ptr->draw_end = 0;
	ray_ptr->ray_dir_x = 0;
	ray_ptr->ray_dir_y = 0;
	ray_ptr->camera_x = 0;
	ray_ptr->side_dist_x = 0;
	ray_ptr->side_dist_y = 0;
	ray_ptr->delta_dist_x = 0;
	ray_ptr->delta_dist_y = 0;
	ray_ptr->wall_dist = 0;
}

void	ft_init_s_gen(t_general *general)
{
	general->mlx_ptr = NULL;
	general->win_ptr = NULL;
	general->win_height = WIN_HEIGHT;
	general->win_width = WIN_WIDTH;
	ft_init_s_player(&general->player_ptr);
	ft_init_s_pst(&general->pst_ptr);
	ft_init_s_txtr(&general->txtr_ptr);
	ft_init_s_map(&general->map_ptr);
	ft_init_s_img(&general->img_ptr);
	general->txtr_pixels = NULL;
	general->txtr = NULL;
}
