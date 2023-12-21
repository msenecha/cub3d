/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:59:43 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/20 22:35:02 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	rotate_left_right(t_general *gen, double rot_speed)
{
	t_player	*p;
	double		tmp_x;

	p = &gen->player_ptr;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = tmp_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	tmp_x = p->plan_x;
	p->plan_x = p->plan_x * cos(rot_speed) - p->plan_y * sin(rot_speed);
	p->plan_y = tmp_x * sin(rot_speed) + p->plan_y * cos(rot_speed);
	return (1);
}

int	rotate_player(t_general *gen, double rot_dir)
{
	int		moved;
	double	rot_speed;

	moved = 0;
	rot_speed = ROTATE * rot_dir;
	moved += rotate_left_right(gen, rot_speed);
	return (moved);
}
