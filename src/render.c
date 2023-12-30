/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:55:41 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/21 01:52:08 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

static void	set_frame(t_general *gen, t_img *image, int x, int y)
{
	if (gen->txtr_pixels[y][x] > 0)
		set_image_pixel(image, x, y, gen->txtr_pixels[y][x]);
	else if (y < WIN_HEIGHT / 2)
		set_image_pixel(image, x, y, gen->txtr_ptr.hex_ceiling);
	else if (y < WIN_HEIGHT -1)
		set_image_pixel(image, x, y, gen->txtr_ptr.hex_floor);
}

static void	render_frame(t_general *gen)
{
	t_img	*image;
	int		x;
	int		y;

	image = &gen->img_ptr;
	image->main_img = NULL;
	init_img(gen, image, WIN_WIDTH, WIN_HEIGHT);
	y = 0;
	while (y < gen->win_height)
	{
		x = 0;
		while (x < gen->win_width)
		{
			set_frame(gen, image, x, y);
			x++;
		}
		y++;
	}
	if (image->main_img != NULL) {
		mlx_put_image_to_window(gen->mlx_ptr, gen->win_ptr, image->main_img, 0, 0);
	}
	mlx_destroy_image(gen->mlx_ptr, image->main_img);
}

static void	render_raycast(t_general *gen)
{
	init_texture_pixels(gen);
	init_ray(&gen->ray_ptr);
	raycasting(&gen->player_ptr, gen);
	render_frame(gen);
}

void	render_images(t_general *gen)
{
	render_raycast(gen);
}

int	render(t_general *gen)
{
	gen->player_ptr.has_moved += move_player(gen);
	if (gen->player_ptr.has_moved == 0)
		return (0);
	render_images(gen);
	return (0);
}
