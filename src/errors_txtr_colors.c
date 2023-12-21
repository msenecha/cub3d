/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_txtr_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:29:59 by svidal            #+#    #+#             */
/*   Updated: 2023/12/21 16:56:49 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_colors(int *color, t_general *general)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

unsigned long	ft_convert_colors_hexa(int *tab)
{
	unsigned long	result;
	int				c1;
	int				c2;
	int				c3;

	c1 = tab[0];
	c2 = tab[1];
	c3 = tab[2];
	result = ((c1 & 0xff) << 16) + ((c2 & 0xff) << 8) + (c3 & 0xff);
	return (result);
}

int	ft_img_ext_error(const char *filename, t_general *gen)
{
	char	*correct_ext;

	correct_ext = ft_strrchr(filename, '.');
	if (correct_ext == NULL || ft_strcmp(correct_ext, ".xpm") != 0 || correct_ext[1] == '\0')
		return (1);
	return (0);
}

void	ft_check_txtr(t_general *gen, char *filename)
{
	if (!gen->txtr_ptr.north || !gen->txtr_ptr.south || !gen->txtr_ptr.east || !gen->txtr_ptr.west)
		return (ft_error_msg("Error: missing texture(s)!\n", gen));
	if (!gen->txtr_ptr.ceiling || !gen->txtr_ptr.floor)
		return (ft_error_msg("Error: missing color(s)!\n", gen));
	if (ft_img_ext_error(gen->txtr_ptr.north, gen) == 1
		|| ft_img_ext_error(gen->txtr_ptr.south, gen) == 1
		|| ft_img_ext_error(gen->txtr_ptr.east, gen) == 1
		|| ft_img_ext_error(gen->txtr_ptr.west, gen) == 1)
		return (ft_error_msg("Error: image file extension must be '.xpm'!\n", gen));
	if (ft_check_colors(gen->txtr_ptr.ceiling, gen) == 1
		|| ft_check_colors(gen->txtr_ptr.ceiling, gen) == 1)
		return (ft_error_msg("Error: wrong color value!\n", gen));
	gen->txtr_ptr.hex_ceiling = ft_convert_colors_hexa(gen->txtr_ptr.ceiling);
	gen->txtr_ptr.hex_floor = ft_convert_colors_hexa(gen->txtr_ptr.floor);
}
