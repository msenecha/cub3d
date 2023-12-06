/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:31:36 by svidal            #+#    #+#             */
/*   Updated: 2023/12/06 17:39:52 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//creation and opening window
void	ft_mlx_win(t_general *general)
{
	general->mlx_ptr = mlx_init();
	if (general->mlx_ptr == NULL)
		ft_error_msg("Error: mlx_ptr cannot be NULL!\n", general);
	//init des img
	//init du player
	general->win_ptr = mlx_new_window(general->mlx_ptr, general->map_ptr.nb_lines * WIN_HEIGHT, general->map_ptr.nb_columns * WIN_WIDTH, WIN_TITLE);
	if (general->win_ptr == NULL)
		ft_error_msg("Error: error with pointer win_ptr", general);
}
