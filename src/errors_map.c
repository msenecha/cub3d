/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:15:08 by svidal            #+#    #+#             */
/*   Updated: 2023/12/13 18:39:10 by msenecha         ###   ########.fr       */
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


//check invalid character inside the map
// NE MARCHE PAAAAASSSSSSSSSSSSSSSSS
/*
void	ft_invalid_char_error(t_general *general)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	//j'ignore lignes vides ou lignes de textures et couleurs

	printf("nb_lines: %d\n", general->map_ptr.nb_lines);
	printf("nb_columns: %d\n", general->map_ptr.nb_columns);
	while (i < general->map_ptr.nb_lines && (ft_strlen(general->map_ptr.map[i]) == 0
			|| ft_white_space(general->map_ptr.map[i])
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
				printf("invalid characters starting from line %d\n", i);
				ft_error_msg("Error: invalid character in the game!\n", general);
				return ;
			}
			j++;
		}
		i++;
	}
}
*/

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
	//j'ignore les lignes qui ne commencent pas par 0 ou 1
	//while (i < general->map_ptr.nb_lines && !ft_ignore_empty_and_config(general->map_ptr.map[i]))
	//	i++;
	//printf("invalid characters starting from line %d\n", i);
	//printf("nb_lines: %d\n", general->map_ptr.nb_lines);
	//printf("nb_columns: %d\n", general->map_ptr.nb_columns);
	while (i < general->map_ptr.map_lines)
	{
		j = 0;
		while (j < general->map_ptr.nb_columns)
		{
			c = general->map_ptr.map_cpy[i][j];
			//check caractere invalide dans la map
			if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0' && c != '1' && c != '\n')
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
