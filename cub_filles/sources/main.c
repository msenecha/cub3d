/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:51:00 by svidal            #+#    #+#             */
/*   Updated: 2024/01/04 16:56:59 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	parse_args(t_data *data, char **av)
{
	if (ft_check_file(av[1], true) == 1)
		ft_exit(data, 1);
	ft_parsing(av[1], data);
	if (ft_data(data, data->mapinfo.file) == 1)
		return (ft_free(data));
	if (ft_map(data, data->map) == 1)
		return (ft_free(data));
	if (ft_txtr(data, &data->texinfo) == 1)
		return (ft_free(data));
	init_player_direction(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (error_msg("Usage", ERROR_USAGE, 1));
	ft_init_data(&data);
	if (parse_args(&data, av) != 0)
		return (1);
	ft_init_mlx(&data);
	ft_init_txtr(&data);
	display_images(&data);
	handle_events(&data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
