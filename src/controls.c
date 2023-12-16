/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:09:00 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/15 19:16:45 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    move_forward(t_general *gen)
{
     if (gen->player_ptr.pst_x)
}

int	ft_close(t_general *gen)
{
	mlx_destroy_image(gen->mlx_ptr, gen->img_ptr.main_img);
	mlx_destroy_window(gen->mlx_ptr, gen->win_ptr);
	mlx_destroy_display(gen->mlx_ptr);
	free (gen->mlx_ptr);
	ft_free_map(gen->map_ptr.map, gen);
	ft_free_map(gen->map_ptr.data, gen);
    free(gen);
	exit(EXIT_SUCCESS);
}
/*
void	move_camera(int key, t_general *gen)
{
	if (key == XK_w)
		move_forward(gen);
	else if (key == XK_s)
		move_backward(gen);
	else if (key == XK_a)
		move_left(gen);
	else if (key == XK_d)
		move_right(gen);
	display_minimap(gen);
}
*/
int	keypress(int keycode, t_general *gen)
{
	if (keycode == XK_Escape)
		ft_close(gen);
	//else if (keycode == XK_w || keycode == XK_s || keycode == XK_a || keycode == XK_d)
	//	move_camera(keycode, gen);
	//else if (keycode == XK_Up || keycode == XK_Down || keycode == XK_Left || keycode == XK_Right)
	//	rotate_camera(keycode, gen);
	return (0);
}

void	ft_handle_events(t_general *gen)
{
	mlx_hook(gen->win_ptr, 2, 1L >> 0, keypress, gen);
	mlx_hook(gen->win_ptr, 17, 1, ft_close, gen);
}