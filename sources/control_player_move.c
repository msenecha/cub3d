/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:30:56 by msenecha          #+#    #+#             */
/*   Updated: 2024/01/05 14:07:04 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVESPEED;
	return (is_valid_move(data, new_x, new_y));
}

static int	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVESPEED;
	return (is_valid_move(data, new_x, new_y));
}

static int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
	return (is_valid_move(data, new_x, new_y));
}

static int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
	return (is_valid_move(data, new_x, new_y));
}

int	player_movements(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_forward(data);
	if (data->player.move_y == -1)
		moved += move_backward(data);
	if (data->player.move_x == -1)
		moved += move_left(data);
	if (data->player.move_x == 1)
		moved += move_right(data);
	if (data->player.rotate != 0)
		moved += player_rotation(data, data->player.rotate);
	return (moved);
}
