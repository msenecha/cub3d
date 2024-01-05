/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msenecha <msenecha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:35:36 by svidal            #+#    #+#             */
/*   Updated: 2024/01/05 16:22:14 by msenecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	error_msg(char *detail, char *str, int code)
{
	if (detail)
		ft_putstr_fd(detail, 2);
	if (str)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n" RESET, 2);
	return (code);
}

int	error_msg_val(int detail, char *str, int code)
{
	(void)detail;
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n" RESET, 2);
	return (code);
}
