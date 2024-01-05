/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:31:24 by svidal            #+#    #+#             */
/*   Updated: 2024/01/05 14:07:04 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	ft_nb_lines(char *path)
{
	int		fd;
	char	*line;
	int		nb_lines;

	nb_lines = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(path, strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			nb_lines++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (nb_lines);
}

static void	ft_fill_tab(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->mapinfo.fd);
	while (line != NULL)
	{
		data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->mapinfo.file[row])
		{
			error_msg(NULL, "Error: m/calloc failed!\n", 0);
			return (ft_free_tab((void **)data->mapinfo.file));
		}
		while (line[i] != '\0')
			data->mapinfo.file[row][column++] = line[i++];
		data->mapinfo.file[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->mapinfo.fd);
	}
	data->mapinfo.file[row] = NULL;
}

void	ft_parsing(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->mapinfo.line_count = ft_nb_lines(path);
	data->mapinfo.path = path;
	data->mapinfo.file = ft_calloc(data->mapinfo.line_count \
			+ 1, sizeof(char *));
	if (!(data->mapinfo.file))
	{
		error_msg(NULL, "Error: m/calloc failed!\n", 0);
		return ;
	}
	data->mapinfo.fd = open(path, O_RDONLY);
	if (data->mapinfo.fd < 0)
		error_msg(path, strerror(errno), 1);
	else
	{
		ft_fill_tab(row, column, i, data);
		close(data->mapinfo.fd);
	}
}
