/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:15:03 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/20 23:49:44 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tab(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	init_texture_pixels(t_general *gen)
{
	int	i;

	if (gen->txtr_pixels)
		free_tab((void **)gen->txtr_pixels);
	gen->txtr_pixels = ft_calloc(gen->win_height + 1,
			sizeof * gen->txtr_pixels);
	if (!gen->txtr_pixels)
		ft_error_msg("Could not allocate memory", gen);
	i = 0;
	while (i < gen->win_height)
	{
		gen->txtr_pixels[i] = ft_calloc(gen->win_width + 1,
				sizeof * gen->txtr_pixels);
		if (!gen->txtr_pixels[i])
			ft_error_msg("Could not allocate memory", gen);
		i++;
	}
}

static void	get_texture_index(t_general *gen, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			gen->txtr_ptr.index = WEST;
		else
			gen->txtr_ptr.index = EAST;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			gen->txtr_ptr.index = SOUTH;
		else
			gen->txtr_ptr.index = NORTH;
	}
}

void	update_texture_pixels(t_general *gen, t_txtr *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(gen, ray);
	tex->tex_x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		tex->tex_x = tex->size - tex->tex_x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - gen->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->tex_y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = gen->txtr[tex->index][tex->size * tex->tex_y + tex->tex_x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			gen->txtr_pixels[y][x] = color;
		y++;
	}
}
