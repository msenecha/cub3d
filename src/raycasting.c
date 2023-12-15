/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:48:50 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/15 11:21:34 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting(t_general *gen)
{
	int		hit;
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		gen->ray_ptr.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		gen->ray_ptr.ray_dir_x = gen->player_ptr.dir_x + gen->player_ptr.plan_x * gen->ray_ptr.camera_x;
		gen->ray_ptr.ray_dir_y = gen->player_ptr.dir_y + gen->player_ptr.plan_y * gen->ray_ptr.camera_x;
		gen->ray_ptr.delta_dist_x = fabs(1 / gen->ray_ptr.ray_dir_x);
		gen->ray_ptr.delta_dist_y = fabs(1 / gen->ray_ptr.ray_dir_y);
		hit = 0;
		if (gen->ray_ptr.ray_dir_x < 0)
		{
			gen->ray_ptr.step_x = -1;
			gen->ray_ptr.side_dist_x = (gen->player_ptr.pst_x - (int)gen->player_ptr.pst_x) * gen->ray_ptr.delta_dist_x;
		}
		else
		{
			gen->ray_ptr.step_x = 1;
			gen->ray_ptr.side_dist_x = ((int)gen->player_ptr.pst_x + 1.0 - gen->player_ptr.pst_x) * gen->ray_ptr.delta_dist_x;
		}
		if (gen->ray_ptr.ray_dir_y < 0)
		{
			gen->ray_ptr.step_y = -1;
			gen->ray_ptr.side_dist_y = (gen->player_ptr.pst_y - (int)gen->player_ptr.pst_y) * gen->ray_ptr.delta_dist_y;
		}
		else
		{
			gen->ray_ptr.step_y = 1;
			gen->ray_ptr.side_dist_y = ((int)gen->player_ptr.pst_y + 1.0 - gen->player_ptr.pst_y) * gen->ray_ptr.delta_dist_y;
		}
		while (hit == 0)
		{
			double tmp_pst_x = gen->player_ptr.pst_x;
			double tmp_pst_y = gen->player_ptr.pst_y;

			if (gen->ray_ptr.side_dist_x < gen->ray_ptr.side_dist_y)
			{
				gen->ray_ptr.side_dist_x += gen->ray_ptr.delta_dist_x;
				tmp_pst_x += gen->ray_ptr.step_x;
				gen->ray_ptr.side = 0;
			}
			else
			{
				gen->ray_ptr.side_dist_y += gen->ray_ptr.delta_dist_y;
				tmp_pst_y += gen->ray_ptr.step_y;
				gen->ray_ptr.side = 1;
			}
			if (gen->map_ptr.map[(int)tmp_pst_y][(int)tmp_pst_x] == '1')
				hit = 1;
		}
	}
}
