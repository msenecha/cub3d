/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:13:45 by svidal            #+#    #+#             */
/*   Updated: 2024/01/05 15:44:53 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	ft_map_content(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
			|| data->map[i][j] == '\r'
			|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (error_msg(data->mapinfo.path, "Invalid char!\n", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (error_msg(data->mapinfo.path, "1 player only!\n", 1));
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_pst(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map_tab[i - 1]) < (size_t)j
		|| ft_strlen(map_tab[i + 1]) < (size_t)j
		|| ft_space(map_tab[i][j - 1]) == 0
		|| ft_space(map_tab[i][j + 1]) == 0
		|| ft_space(map_tab[i - 1][j]) == 0
		|| ft_space(map_tab[i + 1][j]) == 0)
		return (1);
	return (0);
}

static int	ft_player_pst(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (error_msg(data->mapinfo.path,
				"Error: player position not defined!\n", 1));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (ft_pst(data, map_tab) == 1)
		return (error_msg(data->mapinfo.path, "Error:invalid plyr pst!\n", 1));
	return (0);
}

static int	ft_map_pst(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_map_check(t_data *data, char **map_tab)
{
	if (!data->map)
		return (error_msg(data->mapinfo.path, "Error: no map!\n", 1));
	if (ft_map_sides(&data->mapinfo, map_tab) == 1)
		return (error_msg(data->mapinfo.path,
				"Error: missing wall(s) on the edges!\n", 1));
	if (data->mapinfo.height < 3)
		return (error_msg(data->mapinfo.path, "Error: map too small!\n", 1));
	if (ft_map_content(data, map_tab) == 1)
		return (1);
	if (ft_player_pst(data, map_tab) == 1)
		return (1);
	if (ft_map_pst(&data->mapinfo) == 1)
		return (error_msg(data->mapinfo.path,
				"Error: map must be at the end of the file!\n", 1));
	return (0);
}
