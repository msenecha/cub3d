/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:54 by svidal            #+#    #+#             */
/*   Updated: 2023/12/20 16:31:21 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_nb_lines(char *filename, t_general *gen)
{
	char	*line;
	int		fd;
	int		line_nb;

	fd = open(filename, O_RDONLY);
	line_nb = 0;
	line = get_next_line(fd);
	while (line && (line[0] < '0' || line[0] > '9'))
	{
		line_nb++;
		free(line);
		line = get_next_line(fd);
	}
	gen->map_ptr.data_lines = line_nb;
	line_nb = 0;
	while (line != NULL)
	{
		line_nb++;
		free(line);
		line = get_next_line(fd);
	}
	//if (line_nb == 0)
	//	ft_error_msg("Error: missing map in the file!\n", gen);
	gen->map_ptr.map_lines = line_nb;
	close(fd);
}

int	ft_max_line_len(char **map)
{
	int		len_max;
	int		current_len;
	int		i;

	i = 0;
	len_max = 0;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (current_len > len_max)
			len_max = current_len;
		i++;
	}
	return (len_max);
}

char	**ft_copy_map(char **map_cpy, t_general *gen)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc((gen->map_ptr.map_lines + 1) * sizeof(char *));
	while (map_cpy[i])
	{
		map[i] = ft_strdup(map_cpy[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_split_map_2(char *line, int fd, t_general *gen)
{
	int	row;

	row = 0;
	while (line != NULL)
	{
		gen->map_ptr.map_cpy[row] = ft_strdup(line);
		row++;
		free(line);
		line = get_next_line(fd);
	}
	gen->map_ptr.map_cpy[row] = NULL;
	gen->map_ptr.nb_columns = ft_max_line_len(gen->map_ptr.map_cpy);
	close(fd);
	gen->map_ptr.map = ft_copy_map(gen->map_ptr.map_cpy, gen);
	print_tab(gen->map_ptr.data);
	print_tab(gen->map_ptr.map);
}

void	ft_split_map(char *filename, t_general *gen)
{
	int	fd;
	int	row;
	char	*line;

	ft_nb_lines(filename, gen);
	if (gen->map_ptr.nb_lines == 0)
	{
		printf("Error: mising map in the file!\n");
		free(gen);
		exit (0);
	}
	gen->map_ptr.data = malloc((gen->map_ptr.data_lines + 1) * sizeof(char *));
	gen->map_ptr.map_cpy = malloc((gen->map_ptr.map_lines + 1) * sizeof(char *));
	fd = open(filename, O_RDONLY);
	row = 0;
	line = get_next_line(fd);
	while (line[0] < '0' || line[0] > '9')
	{
		gen->map_ptr.data[row] = ft_strdup(line);
		row++;
		free(line);
		line = get_next_line(fd);
	}
	gen->map_ptr.data[row] = NULL;
	ft_split_map_2(line, fd, gen);
}
