/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:30:56 by msenecha          #+#    #+#             */
/*   Updated: 2024/01/05 15:36:20 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static bool	wall_collision(t_data *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	map_position(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->mapinfo.height -0.25)
		return (false);
	return (true);
}

static bool	valid_position(t_data *data, double x, double y)
{
	if (map_position(data, x, y))
		return (true);
	if (wall_collision(data, x, y))
		return (true);
	return (false);
}

int	is_valid_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (valid_position(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (valid_position(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}
