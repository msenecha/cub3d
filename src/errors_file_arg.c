/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_file_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:43:50 by svidal            #+#    #+#             */
/*   Updated: 2023/12/13 19:10:01 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//write all error messages
void	ft_error_msg(char *str, t_general *general)
{
	write(2, str, ft_strlen(str));
	ft_free_map(general->map_ptr.map, general);
	ft_free_map(general->map_ptr.map, general);
	ft_free_map(general->map_ptr.data, general);
	free(general);
	exit(EXIT_FAILURE);
}

//check if the file exists
int	ft_check_file(const char *filename, t_general *general)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	else
	{
		write(2, "Error: the file does not exist!\n", 32);
		free(general);
		return (0);
	}
}
