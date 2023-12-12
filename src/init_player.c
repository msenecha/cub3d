/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:33:25 by svidal            #+#    #+#             */
/*   Updated: 2023/12/12 15:50:41 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// count the number of players
int	ft_nb_players(t_general *general)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < general->map_ptr.nb_lines)
	{
		j = 0;
		while (j < general->map_ptr.nb_columns )
		{
			c = general->map_ptr.map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				general->player_ptr.nb_player++;
			j++;
		}
		i++;
	}
	return (general->player_ptr.nb_player);
}

//init the position of the player
// i et x = ligne
// j et y = colonne
void	ft_pst_player(t_general *general)
{
	int	i;
	int	j;

	i = 0;
	while (general->map_ptr.map[i])
	{
		j = 0;
		while (general->map_ptr.map[i][j])
		{
			if (general->map_ptr.map[i][j] == 'N' || general->map_ptr.map[i][j] == 'S' || general->map_ptr.map[i][j] == 'E' || general->map_ptr.map[i][j] == 'W')
			{
				general->pst_ptr.first_pst_x = i;
				general->pst_ptr.first_pst_y = j;
			}
			j++;
		}
		i++;
	}
}
