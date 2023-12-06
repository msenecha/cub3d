/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:08:23 by svidal            #+#    #+#             */
/*   Updated: 2023/12/06 18:23:21 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//all errors a completer
void	ft_all_errors(t_general *general)
{
	ft_empty_map_error(general);
	//ft_map_wall_error(general);
	ft_invalid_char_error(general);
	ft_wrong_nb_player(general);
}
