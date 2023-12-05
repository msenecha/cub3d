/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:54:52 by msenecha          #+#    #+#             */
/*   Updated: 2023/12/05 20:10:45 by svidal           ###   ########.fr       */
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
		// creation map
		// nb items ?
		ft_map_ext_error(filename, general);
		ft_all_errors(general);
		ft_init_s_gen(general);
		// init mlx, textures
		// img display
		// start game
		// ... ?
		// mlx_loop_hook(); ?
		mlx_loop(general->mlx_ptr);
	}
	return (0);
}
