/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:33:25 by svidal            #+#    #+#             */
/*   Updated: 2023/12/13 20:20:58 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// count the number of players
void	ft_nb_players(t_general *general)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (general->map_ptr.map_cpy[i])
	{
		j = 0;
		while (general->map_ptr.map_cpy[i][j])
		{
			c = general->map_ptr.map_cpy[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				general->player_ptr.nb_player++;
			j++;
		}
		i++;
	}
}

//init the position of the player
// i et x = ligne
// j et y = colonne
void	ft_pst_player(t_general *general)
{
	int	i;
	int	j;

	i = 0;
	while (general->map_ptr.map_cpy[i])
	{
		j = 0;
		while (general->map_ptr.map_cpy[i][j])
		{
			if (general->map_ptr.map_cpy[i][j] == 'N' || general->map_ptr.map_cpy[i][j] == 'S' || general->map_ptr.map_cpy[i][j] == 'E' || general->map_ptr.map_cpy[i][j] == 'W')
			{
				general->pst_ptr.first_pst_x = i;
				general->pst_ptr.first_pst_y = j;
			}
			j++;
		}
		i++;
	}
}
