/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:15:08 by svidal            #+#    #+#             */
/*   Updated: 2023/12/20 14:21:02 by svidal           ###   ########.fr       */
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
	if (general == NULL || general->map_ptr.nb_columns == 0 || general->map_ptr.map_lines == 0)
		ft_error_msg("Error: the file is empty!\n", general);

}

bool	ft_ignore_empty_and_config(char *line)
{
	int	k;

	k = 0;
	if (ft_strlen(line) == 0 || (line[0] != '0' && line[0] != '1'))
		return (false);
	while (line[k] == ' ' || line[k] == '\t')
		k++;
	if (line[k] == '\0' || (line[k] != '1' && line[k] != '0'))
		return (false);
	return (true);
}

void	ft_invalid_char_error(t_general *general)
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
			//check caractere invalide dans la map
			// rajout du \n et de l'espace mais a voir parce que si on en met un au milieu de la map ca marche pas
			if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0' && c != '1' && c != '\n' && c != ' ')
			{
				ft_error_msg("Error: invalid character in the game!\n", general);
				return ;
			}
			j++;
		}
		i++;
	}
}

// check nb players inside the map
void	ft_wrong_nb_player(t_general *general)
{
	if (general->player_ptr.nb_player != 1)
		ft_error_msg("Error: the game must contain 1 player!\n", general);
}
