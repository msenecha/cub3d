/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:59:31 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/21 00:18:33 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	move_player_forward(t_general *gen)
{
	double	new_x;
	double	new_y;

	new_x = gen->player_ptr.pst_x + gen->player_ptr.dir_x * SPEED;
	new_y = gen->player_ptr.pst_y + gen->player_ptr.dir_y * SPEED;
	return (validate_move(gen, new_x, new_y));
}

static int	move_player_backward(t_general *gen)
{
	double	new_x;
	double	new_y;

	new_x = gen->player_ptr.pst_x - gen->player_ptr.dir_x * SPEED;
	new_y = gen->player_ptr.pst_y - gen->player_ptr.dir_y * SPEED;
	return (validate_move(gen, new_x, new_y));
}

static int	move_player_left(t_general *gen)
{
	double	new_x;
	double	new_y;

	new_x = gen->player_ptr.pst_x + gen->player_ptr.dir_y * SPEED;
	new_y = gen->player_ptr.pst_y - gen->player_ptr.dir_x * SPEED;
	return (validate_move(gen, new_x, new_y));
}

static int	move_player_right(t_general *gen)
{
	double	new_x;
	double	new_y;

	new_x = gen->player_ptr.pst_x - gen->player_ptr.dir_y * SPEED;
	new_y = gen->player_ptr.pst_y + gen->player_ptr.dir_x * SPEED;
	return (validate_move(gen, new_x, new_y));
}

int	move_player(t_general *gen)
{
	int	moved;

	moved = 0;
	if (gen->player_ptr.move_y == 1)
		moved += move_player_forward(gen);
	if (gen->player_ptr.move_y == -1)
		moved += move_player_backward(gen);
	if (gen->player_ptr.move_x == -1)
		moved += move_player_left(gen);
	if (gen->player_ptr.move_x == 1)
		moved += move_player_right(gen);
	if (gen->player_ptr.rotate != 0)
		moved += rotate_player(gen, gen->player_ptr.rotate);
	return (moved);
}
