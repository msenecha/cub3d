/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_txtr_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:40:58 by svidal            #+#    #+#             */
/*   Updated: 2024/01/04 16:55:21 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	ft_digit(char *str)
{
	int		i;
	bool	no_digit;

	i = 0;
	no_digit = true;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			no_digit = false;
		i++;
	}
	return (no_digit);
}

static int	*ft_tab_cpy(char **rgb_to_convert, int *rgb)
{
	int		i;

	i = -1;
	while (rgb_to_convert[++i])
	{
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		if (rgb[i] == -1 || ft_digit(rgb_to_convert[i]) == true)
		{
			ft_free_tab((void **)rgb_to_convert);
			free(rgb);
			return (0);
		}
	}
	ft_free_tab((void **)rgb_to_convert);
	return (rgb);
}

static int	*ft_colors(char *line)
{
	char	**new_i;
	int		*i;
	int		count;

	new_i = ft_split(line, ',');
	count = 0;
	while (new_i[count])
		count++;
	if (count != 3)
	{
		ft_free_tab((void **)new_i);
		return (0);
	}
	i = malloc(sizeof(int) * 3);
	if (!i)
	{
		error_msg(NULL, "Error: m/calloc failed!\n", 0);
		return (0);
	}
	return (ft_tab_cpy(new_i, i));
}

int	ft_color_txtr(t_data *data, t_texture *textures, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
		return (error_msg(data->mapinfo.path,
				"Error: invalid floor or ceiling color(s)!\n", ERROR));
	if (!textures->ceiling && line[j] == 'C')
	{
		textures->ceiling = ft_colors(line + j + 1);
		if (textures->ceiling == 0)
			return (error_msg(data->mapinfo.path,
					"Error: invalid ceiling color!\n", ERROR));
	}
	else if (!textures->floor && line[j] == 'F')
	{
		textures->floor = ft_colors(line + j + 1);
		if (textures->floor == 0)
			return (error_msg(data->mapinfo.path,
					"Error: invalid floor color!\n", ERROR));
	}
	else
		return (error_msg(data->mapinfo.path,
				"Error: invalid floor or ceiling color(s)!\n", ERROR));
	return (0);
}
