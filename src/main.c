/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/12/21 01:26:29 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

int	every_bloody_error(char *filename, t_general *gen)
{
	if (ft_check_file(filename, gen) == 0)
			return (1);
	ft_split_map(filename, gen);
	ft_pst_player(gen);
	ft_nb_players(gen);
	ft_map_ext_error(filename, gen);
	ft_all_errors(gen);
	ft_free_map(gen->map_ptr.map_cpy, gen);
	return (0);
}

int	main(int argc, char **argv)
{
	t_general	*gen;

	gen = malloc(sizeof(t_general));
	if (gen == NULL)
		return (free(gen), gen = NULL, 0);
	if (argc != 2)
		ft_error_msg("Error: no file specified!\n", gen);
	else
	{
		ft_init_s_gen(gen);
		if(every_bloody_error(argv[1], gen))
			return (1);
		player_direction(gen);
		ft_mlx_win(gen);
		render_images(gen);
		//display_minimap(gen);
		//mlx_put_image_to_window(gen->mlx_ptr, gen->win_ptr, gen->img_ptr.main_img, 0, WIN_HEIGHT - (MINI_TILESIZE * gen->map_ptr.map_lines));
		ft_handle_events(gen);
		// init mlx, textures
		// img display
		// start game
		// ... ?

		//ft_exit_game(general);
		// mlx_loop_hook(); ?
		mlx_loop(gen->mlx_ptr);
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
