/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:03:23 by svidal            #+#    #+#             */
/*   Updated: 2024/01/05 14:44:08 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static char	*ft_txtr_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

static int	ft_direct_txtr(t_texture *textures, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2]))
		return (ERROR);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->north))
		textures->north = ft_txtr_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->south))
		textures->south = ft_txtr_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->west))
		textures->west = ft_txtr_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->east))
		textures->east = ft_txtr_path(line, j + 2);
	else
		return (ERROR);
	return (0);
}

static int	ft_ign_spaces(t_data *data, char **map, int i, int j)
{
	while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\n')
		j++;
	if (ft_isprint(map[i][j]) && !ft_isdigit(map[i][j]))
	{
		if (map[i][j + 1] && ft_isprint(map[i][j + 1])
			&& !ft_isdigit(map[i][j]))
		{
			if (ft_direct_txtr(&data->texinfo, map[i], j) == ERROR)
				return (error_msg(data->mapinfo.path, "Invalid txtr!\n", 1));
			return (BREAK);
		}
		else
		{
			if (ft_color_txtr(data, &data->texinfo, map[i], j) == ERROR)
				return (1);
			return (BREAK);
		}
	}
	else if (ft_isdigit(map[i][j]))
	{
		if (ft_creation_map(data, map, i) == 1)
			return (error_msg(data->mapinfo.path, "Error: invalid map!\n", 1));
		return (0);
	}
	return (CONTINUE);
}

int	ft_data(t_data *data, char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ret = ft_ign_spaces(data, map, i, j);
			if (ret == BREAK)
				break ;
			else if (ret == 1)
				return (1);
			else if (ret == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (0);
}
