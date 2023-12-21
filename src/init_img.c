/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:15:35 by svidal            #+#    #+#             */
/*   Updated: 2023/12/21 15:16:19 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_img(t_general *gen, t_img *image, int width, int height)
{
	ft_init_s_img(image);
	image->main_img = mlx_new_image(gen->mlx_ptr, width, height);
	if (image->main_img == NULL)
		ft_error_msg("Error: mlx_new_image failed!\n", gen);
	image->addr = mlx_get_data_addr(image->main_img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

void	init_texture_img(t_general *gen, t_img *image, char *path)
{
	t_txtr *tex;

	tex = &gen->txtr_ptr;
	ft_init_s_img(image);
	image->main_img = mlx_xpm_file_to_image(gen->mlx_ptr, path, &tex->size,
			&tex->size);
	if (image->main_img == NULL)
		ft_error_msg("Error: mlx_new_image failed!\n", gen);
	image->addr = mlx_get_data_addr(image->main_img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}
