/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:09:00 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/20 21:18:48 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	key_release(int key, t_general *gen)
{
	if (key == XK_Escape)
		ft_close(gen);
	if (key == XK_w && gen->player_ptr.move_y == 1)
		gen->player_ptr.move_y = 0;
	if (key == XK_s && gen->player_ptr.move_y == -1)
		gen->player_ptr.move_y = 0;
	if (key == XK_a && gen->player_ptr.move_x == -1)
		gen->player_ptr.move_x += 1;
	if (key == XK_d && gen->player_ptr.move_x == 1)
		gen->player_ptr.move_x -= 1;
	if (key == XK_Left && gen->player_ptr.rotate <= 1)
		gen->player_ptr.rotate = 0;
	if (key == XK_Right && gen->player_ptr.rotate >= -1)
		gen->player_ptr.rotate = 0;
	return (0);
}

int	keypress(int keycode, t_general *gen)
{
	if (keycode == XK_Escape)
		ft_close(gen);
	if (keycode == XK_Left)
		gen->player_ptr.rotate -= 1;
	if (keycode == XK_Right)
		gen->player_ptr.rotate += 1;
	if (keycode == XK_w)
		gen->player_ptr.move_y = 1;
	if (keycode == XK_a)
		gen->player_ptr.move_x = -1;
	if (keycode == XK_s)
		gen->player_ptr.move_y = -1;
	if (keycode == XK_d)
		gen->player_ptr.move_x = 1;
	return (0);
}

void	ft_handle_events(t_general *gen)
{
	mlx_hook(gen->win_ptr, 2, 1L<<0, keypress, gen);
	mlx_hook(gen->win_ptr, 3, 1L<<1, key_release, gen);
	mlx_hook(gen->win_ptr, 17, 1, ft_close, gen);
}
