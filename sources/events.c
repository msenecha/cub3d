/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:30:56 by msenecha          #+#    #+#             */
/*   Updated: 2024/01/05 15:25:57 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	press_key(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_exit_game(data);
	if (key == XK_Left)
		data->player.rotate -= 1;
	if (key == XK_Right)
		data->player.rotate += 1;
	if (key == XK_w)
		data->player.move_y = 1;
	if (key == XK_a)
		data->player.move_x = -1;
	if (key == XK_s)
		data->player.move_y = -1;
	if (key == XK_d)
		data->player.move_x = 1;
	return (0);
}

static int	release_key(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_exit_game(data);
	if (key == XK_w && data->player.move_y == 1)
		data->player.move_y = 0;
	if (key == XK_s && data->player.move_y == -1)
		data->player.move_y = 0;
	if (key == XK_a && data->player.move_x == -1)
		data->player.move_x += 1;
	if (key == XK_d && data->player.move_x == 1)
		data->player.move_x -= 1;
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

void	handle_events(t_data *data)
{
	mlx_hook(data->win, ClientMessage, NoEventMask, ft_exit_game, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, press_key, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, release_key, data);
}
