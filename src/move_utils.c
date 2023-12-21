/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:00:13 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/20 22:41:37 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	wall_collision(t_general *gen, double x, double y)
{
	if (gen->map_ptr.map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	map_position(t_general *gen, double x, double y)
{
	if (x < 0.25 || x >= gen->map_ptr.nb_columns - 1.25)
		return (false);
	if (y < 0.25 || y >= gen->map_ptr.map_lines -0.25)
		return (false);
	return (true);
}

static bool	valid_position(t_general *gen, double x, double y)
{
	if (map_position(gen, x, y))
		return (true);
	if (wall_collision(gen, x, y))
		return (true);
	return (false);
}

int	validate_move(t_general *gen, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (valid_position(gen, new_x, gen->player_ptr.pst_y))
	{
		gen->player_ptr.pst_x = new_x;
		moved = 1;
	}
	if (valid_position(gen, gen->player_ptr.pst_x, new_y))
	{
		gen->player_ptr.pst_y = new_y;
		moved = 1;
	}
	return (moved);
}
