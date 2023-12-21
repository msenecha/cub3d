/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:08:23 by svidal            #+#    #+#             */
/*   Updated: 2023/12/20 16:08:24 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_wall_error(t_general *general, int i, int j)
{
	if (!general->map_ptr.map || !general->map_ptr.map[i] || !general->map_ptr.map[i][j])
		return (1);
	while (general->map_ptr.map[i][j] == ' ' || general->map_ptr.map[i][j] == '\t')
		j++;
	while (general->map_ptr.map[i][j] != '\n')
	{
		if (general->map_ptr.map[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

void	ft_map_wall_error(t_general *general)
{
	int	i;
	int	j;

	if (ft_check_wall_error(general, 0, 0) == 1)
		return (ft_error_msg("1 Error: missing wall(s) on the edges!\n", general));
	i = 1;
	while (i < general->map_ptr.nb_lines)
	{
		j = ft_strlen(general->map_ptr.map[i] - 1);
		if (general->map_ptr.map[i][j] != '1')
			return (ft_error_msg("2 Error: missing wall(s) on the edges!\n", general));
		i++;
	}
	i--;
	if (ft_check_wall_error(general, i, 0) == 1)
		return (ft_error_msg("3 Error: missing wall(s) on the edges!\n", general));
}




//all errors a completer
void	ft_all_errors(t_general *general)
{
	ft_empty_map_error(general);
	ft_map_wall_error(general);
	ft_invalid_char_error(general);
	ft_wrong_nb_player(general);
}
