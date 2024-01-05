/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:30:56 by msenecha          #+#    #+#             */
/*   Updated: 2024/01/05 15:36:57 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	set_frame_txtr(t_data *data, t_image *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		my_put_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < data->win_height / 2)
		my_put_pixel(image, x, y, data->texinfo.hex_ceiling);
	else if (y < data->win_height -1)
		my_put_pixel(image, x, y, data->texinfo.hex_floor);
}

static void	build_frame(t_data *data)
{
	t_image	image;
	int		x;
	int		y;

	image.img = NULL;
	ft_init_image(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_frame_txtr(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, image.img, 0, 0);
	mlx_destroy_image(data->mlx, image.img);
}

static void	setup_raycast(t_data *data)
{
	set_pixel_txtr(data);
	ft_init_ray(&data->ray);
	raycastor(&data->player, data);
	build_frame(data);
}

int	display_images(t_data *data)
{
	setup_raycast(data);
	return (0);
}

int	rendering_frame(t_data *data)
{
	data->player.has_moved += player_movements(data);
	if (data->player.has_moved == 0)
		return (0);
	display_images(data);
	return (0);
}
