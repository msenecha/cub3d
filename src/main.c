/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:54:52 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/12 16:10:30 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	char		*filename;
	t_general	*general;

	general = malloc(sizeof(t_general));
	if (general == NULL)
		return (free(general), general = NULL, 0);
	if (argc != 2)
		ft_error_msg("Error: no file specified!\n", general);
	else
	{
		filename = argv[1];
		if (ft_check_file(filename, general) == 0)
			return (1);
		ft_creation_map(filename, general);
		ft_pst_player(general);
		ft_nb_players(general);
		printf("nb joueur(s): %d\n", general->player_ptr.nb_player);
		ft_map_ext_error(filename, general);
		ft_all_errors(general);
		ft_init_s_gen(general);


		ft_mlx_win(general);
		// init mlx, textures
		// img display
		// start game
		// ... ?

		//ft_exit_game(general);
		// mlx_loop_hook(); ?
		mlx_loop(general->mlx_ptr);
	}
	return (0);
}


/*probleme actuel :
si 2 joueurs dans la map :

 ./cub3d ./maps/invalid\ maps/only_map.cub
nb joueur(s): -1094795584 (printf dans main)
nb joueur(s): -1094795584 (printf dans ft_wrong_nb_players)
Error: the game must contain 1 player!

si 0 joueur dans la map :

 ./cub3d ./maps/invalid\ maps/only_map.cub
nb joueur(s): -1094795586
nb joueur(s): -1094795586
Error: the game must contain 1 player!

je ne recupere pas le nb de joueurs.
Je me suis embrouillee entre les trucs a initialiser avant les fonctions d'erreurs,
et les trucs a initialiser apres. J'avais eu le meme pb dans so long...
*/
