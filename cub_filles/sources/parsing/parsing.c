/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuster- <vfuster-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:18:09 by vfuster-          #+#    #+#             */
/*   Updated: 2023/12/14 15:59:08 by vfuster-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	get_number_of_lines(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(path, strerror(errno), errno);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

static void	fill_tab(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->mapinfo.fd);
	while (line != NULL)
	{
		data->mapinfo.file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->mapinfo.file[row])
		{
			error_msg(NULL, ERROR_MALLOC, 0);
			return (free_tab((void **)data->mapinfo.file));
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

void	parse_data(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->mapinfo.line_count = get_number_of_lines(path);
	data->mapinfo.path = path;
	data->mapinfo.file = ft_calloc(data->mapinfo.line_count \
			+ 1, sizeof(char *));
	if (!(data->mapinfo.file))
	{
		error_msg(NULL, ERROR_MALLOC, 0);
		return ;
	}
	data->mapinfo.fd = open(path, O_RDONLY);
	if (data->mapinfo.fd < 0)
		error_msg(path, strerror(errno), 1);
	else
	{
		fill_tab(row, column, i, data);
		close(data->mapinfo.fd);
	}
}
