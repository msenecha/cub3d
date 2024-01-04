/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:57:51 by svidal            #+#    #+#             */
/*   Updated: 2024/01/04 16:57:56 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_free_tab(void **tab)
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

static void	ft_free_txtr(t_texture *textures)
{
	if (textures->north)
		free(textures->north);
	if (textures->south)
		free(textures->south);
	if (textures->west)
		free(textures->west);
	if (textures->east)
		free(textures->east);
	if (textures->floor)
		free(textures->floor);
	if (textures->ceiling)
		free(textures->ceiling);
}

static void	ft_free_map(t_data *data)
{
	if (data->mapinfo.fd > 0)
		close(data->mapinfo.fd);
	if (data->mapinfo.file)
		ft_free_tab((void **)data->mapinfo.file);
	if (data->map)
		ft_free_tab((void **)data->map);
}

int	ft_free(t_data *data)
{
	if (data->textures)
		ft_free_tab((void **)data->textures);
	if (data->texture_pixels)
		ft_free_tab((void **)data->texture_pixels);
	ft_free_txtr(&data->texinfo);
	ft_free_map(data);
	return (1);
}
