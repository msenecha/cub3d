/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtr_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:49:03 by svidal            #+#    #+#             */
/*   Updated: 2024/01/05 14:07:04 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	ft_check_colors_values(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (error_msg_val(rgb[i], "Error: wrong color(s) value!\n", 1));
		i++;
	}
	return (0);
}

static unsigned long	ft_convert_hexa(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	ft_txtr(t_data *data, t_texture *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (error_msg(data->mapinfo.path,
				"Error: missing texture(s)!\n", 1));
	if (!textures->floor || !textures->ceiling)
		return (error_msg(data->mapinfo.path, "Error: missing color(s)!\n", 1));
	if (ft_check_file(textures->north, false) == 1
		|| ft_check_file(textures->south, false) == 1
		|| ft_check_file(textures->west, false) == 1
		|| ft_check_file(textures->east, false) == 1
		|| ft_check_colors_values(textures->floor) == 1
		|| ft_check_colors_values(textures->ceiling) == 1)
		return (1);
	textures->hex_floor = ft_convert_hexa(textures->floor);
	textures->hex_ceiling = ft_convert_hexa(textures->ceiling);
	return (0);
}
