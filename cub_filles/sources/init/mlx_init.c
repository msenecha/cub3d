/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:39:05 by svidal            #+#    #+#             */
/*   Updated: 2024/01/04 16:52:47 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_img(t_data *data, t_img *image, int width, int height)
{
	ft_init_img(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		ft_exit(data, error_msg("mlx",
				"Error: mlx image creation failed!\n", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	ft_init_txtr_img(t_data *data, t_img *image, char *path)
{
	ft_init_img(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path, &data->texinfo.size,
			&data->texinfo.size);
	if (image->img == NULL)
		ft_exit(data, error_msg("mlx",
				"Error: mlx image creation failed!\n", 1));
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit(data, error_msg("mlx", "Error: mlx not started!\n", 1));
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		ft_exit(data, error_msg("mlx",
				"Error: mlx window creation failed!\n", 1));
	return ;
}
