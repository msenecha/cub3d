/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:31:36 by svidal            #+#    #+#             */
/*   Updated: 2023/12/13 18:31:10 by msenecha         ###   ########.fr       */
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
	general->win_ptr = mlx_new_window(general->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (general->win_ptr == NULL)
		ft_error_msg("Error: error with pointer win_ptr", general);
}
