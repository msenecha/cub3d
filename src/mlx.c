/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:31:36 by svidal            #+#    #+#             */
/*   Updated: 2023/12/14 11:54:21 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_general *gen, int x, int y, int color)
{
	int		i;

	if ( x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	i = (x * gen->img_ptr.pixel_bits / 8) + (y * gen->img_ptr.size_line);
	gen->img_ptr.addr[i] = color;
	gen->img_ptr.addr[++i] = color >> 8;
	gen->img_ptr.addr[++i] = color >> 16;
}


void display_minimap(t_general *general)
{
	int x;
	int y;
	int color;
	int i;
	int j;

	y = 0;
	while (y < general->map_ptr.map_lines)
	{
		x = 0;
		while (x < general->map_ptr.nb_columns - 1)
		{
			if (general->map_ptr.map[y][x] == '0')
				color = 0x00FF0000;
			else if (general->map_ptr.map[y][x] == '1')
				color = 0x000000FF;
			else if (general->map_ptr.map[y][x] == ' ')
				color = 0x00222222;
			else
				color = 0x00FFFFFF;
			i = 0;
			while (i < MINI_TILESIZE)
			{
				j = 0;
				while (j < MINI_TILESIZE)
				{
					put_pixel(general, x * MINI_TILESIZE + i, y * MINI_TILESIZE + j, color);
					j++;
				}
				i++;
			}
			x++;
		}
		y++;
	}
}


//creation and opening window
void	ft_mlx_win(t_general *general)
{
	general->mlx_ptr = mlx_init();
	if (general->mlx_ptr == NULL)
		ft_error_msg("Error: mlx_ptr cannot be NULL!\n", general);
	//init des img
	//init du player
	general->win_ptr = mlx_new_window(general->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (general->win_ptr == NULL)
		ft_error_msg("Error: error with pointer win_ptr", general);
	general->img_ptr.main_img = mlx_new_image(general->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (general->img_ptr.main_img == NULL)
		ft_error_msg("Error: minimap image not initialized", general);
	general->img_ptr.addr = mlx_get_data_addr(general->img_ptr.main_img,
			&general->img_ptr.pixel_bits, &general->img_ptr.size_line,
			&general->img_ptr.endian);
	if (general->img_ptr.addr == NULL)
		ft_error_msg("Error: minimap image not initialized", general);
	display_minimap(general);
	mlx_put_image_to_window(general->mlx_ptr, general->win_ptr, general->img_ptr.main_img, 0, WIN_HEIGHT - 32 * general->map_ptr.map_lines);
}
