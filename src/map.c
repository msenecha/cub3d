/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:54 by svidal            #+#    #+#             */
/*   Updated: 2023/12/12 15:53:55 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_nb_lines_map(char *filename, t_general *general)
{
	char	*line;
	int		fd;

	general->map_ptr.nb_lines = 0;
	if (ft_check_file(filename, general) == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		general->map_ptr.nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return(general->map_ptr.nb_lines);
}

int	ft_max_line_len(char *filename)
{
	char	*line;
	int		fd;
	int		len_max;
	int		current_len;

	fd = open(filename, O_RDONLY);
	len_max = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		current_len = ft_strlen(line);
		if (current_len > len_max)
			len_max = current_len;
		free(line);
	}
	close(fd);
	return (len_max);
}

void	ft_fill_map(int fd, int row, int column, t_general *general)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		general->map_ptr.map[row] = malloc((ft_strlen(line) + 1) * sizeof(char));
		if (general->map_ptr.map[row] == NULL)
		{
			ft_free_map(general->map_ptr.map, general);
			return ;
		}
		while (line[i] != '\0')
			general->map_ptr.map[row][column++] = line[i++];
		general->map_ptr.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(fd);
	}
	general->map_ptr.map[row] = NULL;
	free(general->map_ptr.map[row]);
}

void	ft_creation_map(char *filename, t_general *general)
{
	int	column;
	int	row;
	int	fd;

	column = 0;
	row = 0;
	//general->map_ptr.map = NULL;
	general->map_ptr.nb_lines = ft_nb_lines_map(filename, general);
	general->map_ptr.nb_columns = ft_max_line_len(filename);
	general->map_ptr.map = malloc((general->map_ptr.nb_lines + 1) * sizeof(char *));
	if (general->map_ptr.map == NULL)
		return ;
	if (ft_check_file(filename, general) == 0)
		return ;
	fd = open(filename, O_RDONLY);
	ft_fill_map(fd, row, column, general);
	close(fd);
}
