/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:05:14 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/21 16:36:05 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*get_texture_path(char *line, int j)
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

static int	fill_direction_textures(t_txtr *textures, char *line, int j)
{
	//if (line[j + 2] && ft_isprint(line[j + 2]))
	//	return (1);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(textures->north))
		textures->north = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(textures->south))
		textures->south = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(textures->west))
		textures->west = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(textures->east))
		textures->east = get_texture_path(line, j + 2);
	//else
	//	return (1);
	return (0);
}

static int	ignore_whitespaces_get_info(t_general *gen, char **data, int i, int j)
{
	t_txtr  *tex;

    tex = &gen->txtr_ptr;
    while (data[i][j] == ' ' || data[i][j] == '\t' || data[i][j] == '\n')
		j++;
	if (ft_isprint(data[i][j]) && !ft_isdigit(data[i][j]))
	{
		if (data[i][j + 1] && ft_isprint(data[i][j + 1])
			&& !ft_isdigit(data[i][j]))
		{
			if (fill_direction_textures(tex, data[i], j) == 1)
				ft_error_msg("Error: texture path", gen);
			return (1);
		}
		else
		{
			if (fill_color_textures(gen, tex, data[i], j) == 1)
				ft_error_msg("Error: color values", gen);
			return (1);
		}
	}
	return (0);
}

int	get_file_gen(t_general *gen, char **data)
{
	int	i;
	int	j;
    int	ret;

	i = 0;
	while (data[i])
	{
        //printf("data[i] = %s\n", data[i]);
		j = 0;
        if (data[i][j] != '\n')
        {
		    while (data[i][j])
		    {
			    ret = ignore_whitespaces_get_info(gen, data, i, j);
			    if (ret == 1)
				    break ;
			    //if (ret == 1)
				//    return (1);
			    //else if (ret == 0)
				//    return (0);
                j++;
            }
        }
	    i++;
	}
    return (0);
}
