/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_file_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:41:27 by svidal            #+#    #+#             */
/*   Updated: 2024/01/04 15:46:33 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static bool	ft_check_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = true;
	}
	return (ret);
}

static bool	ft_check_ext_cub(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

static bool	ft_check_ext_xpm(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

int	ft_check_file(char *arg, bool cub)
{
	int	fd;

	if (ft_check_dir(arg))
		return (error_msg(arg, "Error: you are in a directory\n", 1));
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (error_msg(arg, strerror(errno), 1));
	close(fd);
	if (cub && !ft_check_ext_cub(arg))
		return (error_msg(arg, "Error: file extension must be '.cub'!\n", 1));
	if (!cub && !ft_check_ext_xpm(arg))
		return (error_msg(arg, "Error: file extension must be '.xpm'!\n", 1));
	return (0);
}
