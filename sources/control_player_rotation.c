/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_rotation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:30:56 by msenecha          #+#    #+#             */
/*   Updated: 2024/01/05 14:07:04 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	rotate_left_right(t_data *data, double rot_speed)
{
	t_player	*p;
	double		tmp_x;

	p = &data->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = tmp_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = tmp_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
	return (1);
}

int	player_rotation(t_data *data, double rot_dir)
{
	int		moved;
	double	rot_speed;

	moved = 0;
	rot_speed = ROTSPEED * rot_dir;
	moved += rotate_left_right(data, rot_speed);
	return (moved);
}
