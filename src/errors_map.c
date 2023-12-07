/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:15:08 by svidal            #+#    #+#             */
/*   Updated: 2023/12/07 17:33:58 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//check map extension -> OK
void	ft_map_ext_error(const char *filename, t_general *general)
{
	char	*correct_ext;

	correct_ext = ft_strrchr(filename, '.');
	if (correct_ext == NULL || ft_strcmp(correct_ext, ".cub") != 0 || correct_ext[1] == '\0')
		ft_error_msg("Error: file extension must be '.cub'!\n", general);
}

//empty map -> OK
void	ft_empty_map_error(t_general *general)
{
	if (general == NULL || general->map_ptr.nb_columns == 0 || general->map_ptr.nb_lines == 0)
		ft_error_msg("Error: the file is empty!\n", general);

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
//NE MARCHE PAS
/*
void	ft_invalid_char_error(t_general *general)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	//j'ignore lignes vides ou lignes de textures et couleurs
	printf("general->map_ptr.nb_lines: %d\n", general->map_ptr.nb_lines);
	while (i < general->map_ptr.nb_lines && (ft_strlen(general->map_ptr.map[i]) == 0
			|| ft_strcmp(general->map_ptr.map[i], "NO") == 0
			|| ft_strcmp(general->map_ptr.map[i], "SO") == 0
			|| ft_strcmp(general->map_ptr.map[i], "WE") == 0
			|| ft_strcmp(general->map_ptr.map[i], "EA") == 0
			|| ft_strcmp(general->map_ptr.map[i], "F") == 0
			|| ft_strcmp(general->map_ptr.map[i], "C") == 0
			|| ft_strcmp(general->map_ptr.map[i], " ") == 0
			|| ft_strcmp(general->map_ptr.map[i], "\t") == 0))
		i++;

	while (i < general->map_ptr.nb_lines)
	{
		j = 0;
		while (j < general->map_ptr.nb_columns)
		{
			c = general->map_ptr.map[i][j];
			//check caractere invalide dans la map
			if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0' && c != '1')
			{
				ft_error_msg("Error: invalid character in the game!\n", general);
				return ;
			}
			j++;
		}
		i++;
	}
}
*/
void	ft_invalid_char_error(t_general *general)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	//j'ignore les lignes qui ne commencent pas par 0 ou 1
	while (i < general->map_ptr.nb_lines && (general->map_ptr.map[i][0] != '1' && general->map_ptr.map[i][0] != '0'))
		i++;
	printf("nb_lines: %d\n", general->map_ptr.nb_lines);
	printf("nb_columns: %d\n", general->map_ptr.nb_columns);
	while (i < general->map_ptr.nb_lines)
	{
		j = 0;
		while (j < general->map_ptr.nb_columns)
		{
			c = general->map_ptr.map[i][j];
			//check caractere invalide dans la map
			if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0' && c != '1')
			{
				ft_error_msg("Error: invalid character in the game!\n", general);
				return ;
			}
			j++;
		}
		i++;
	}
}

// check nb players inside the map -> OK
void	ft_wrong_nb_player(t_general *general)
{
	char	c;
	int		nb_players;
	int		i;
	int		j;

	nb_players = 0;
	i = 1;
	while (i < general->map_ptr.nb_lines - 1)
	{
		j = 1;
		while (j < general->map_ptr.nb_columns - 1)
		{
			c = general->map_ptr.map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				nb_players++;
			j++;
		}
		i++;
	}
	if (nb_players != 1)
		ft_error_msg("Error: the game must contain 1 player!\n", general);
}
