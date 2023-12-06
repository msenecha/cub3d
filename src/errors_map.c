/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:15:08 by svidal            #+#    #+#             */
/*   Updated: 2023/12/06 18:27:53 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//check map extension
void	ft_map_ext_error(const char *filename, t_general *general)
{
	char	*correct_ext;

	correct_ext = ft_strrchr(filename, '.');
	if (correct_ext == NULL || ft_strcmp(correct_ext, ".cub") != 0 || correct_ext[1] == '\0')
		ft_error_msg("Error: file extension must be '.cub'!\n", general);
}

//empty map
//verifier si j'ai le droit d'avoir une ligne vide au debut du fichier
void	ft_empty_map_error(t_general *general)
{
	size_t	first_line_len;

	if (general == NULL)
		ft_error_msg("Error: the file is empty!\n", general);
	first_line_len = ft_strlen(general->map_ptr.map[0]);
	general->map_ptr.nb_columns = first_line_len - 1;
	if (general->map_ptr.nb_columns == 0 || general->map_ptr.nb_lines == 0)
		ft_error_msg("Error: the map is empty!\n", general);
}

//check walls at the edges
// VERIFIER SI AJOUT DU -1 SUFFIT POUR CHECK LES MURS
/*
void	ft_map_wall_error(t_general *general)
{
	int	i;
	int	j;

	i = 0;
	while (i < general->map_ptr.nb_lines - 1)
	{
		j = 0;
		while (j < general->map_ptr.nb_columns - 1)
		{
			if ( i == 0 || j == 0 || i == general->map_ptr.nb_lines - 1 || j == general->map_ptr.nb_columns - 1)
			{
				if (general->map_ptr.map[i][j] != '1')
					ft_error_msg("Error: missing wall(s) on the edges!\n", general);
			}
			j++;
		}
		i++;
	}
}
*/

//check invalid character inside the map
//check que dans la map en ignorant les infos du dessus
void	ft_invalid_char_error(t_general *general)
{
	char	cell;
	int		i;
	int		j;

	i = 0;
	while (i < general->map_ptr.nb_lines)
	{
		j = 0;
		while (j < general->map_ptr.nb_columns)
		{
			cell = general->map_ptr.map[i][j];
			if (cell != 'N' && cell != 'S' && cell != 'E' && cell != 'W' && cell != '0' && cell != '1')
			{
				ft_error_msg("Error: invalid character in the game!\n", general);
				return ;
			}
			j++;
		}
		i++;
	}
}

//pas bon compter le nb de player ds la map avec les 4 lettres
void	ft_wrong_nb_player(t_general *general)
{
	if (general->player_ptr.nb_player != 1)
		ft_error_msg("Error: the game must contain 1 player!\n", general);
}
