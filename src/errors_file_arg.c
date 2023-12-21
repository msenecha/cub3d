/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_file_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:43:50 by svidal            #+#    #+#             */
/*   Updated: 2023/12/21 16:42:22 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//write all error messages
void	ft_error_msg(char *str, t_general *general)
{
	write(2, str, ft_strlen(str));
	ft_free_map(general->map_ptr.map, general);
	ft_free_map(general->map_ptr.map_cpy, general);
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
		return (0);
	}
	else
	{
		write(2, "Error: the file does not exist!\n", 32);
		free(general);
		return (1);
	}
}

bool	ft_file_dir(char *filename)
{
	int		fd;
	bool	result;

	result = false;
	fd = open(filename, __O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		result = true;
	}
	return (result);
}
