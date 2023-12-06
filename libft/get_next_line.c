/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <svidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:05:50 by svidal            #+#    #+#             */
/*   Updated: 2023/12/06 17:26:30 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_reading(int fd, char *storage)
{
	int		len;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	len = 1;
	while (len > 0 && !ft_strchr(storage, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		buff[len] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

char	*ft_get_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof (char));
	if (!line)
		return (NULL);
	i = -1;
	while (storage[++i] && storage[i] != '\n')
		line[i] = storage[i];
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_extract_rest(char *storage)
{
	int		i;
	int		j;
	char	*line;

	if (!storage)
		return (free(storage), storage = NULL, NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = (char *)malloc(ft_strlen(storage) - i + 1);
	j = 0;
	while (storage[i])
		line[j++] = storage[i++];
	line[j] = '\0';
	free(storage);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (storage)
			return (free(storage), storage = NULL, NULL);
		return (NULL);
	}
	if (!ft_strchr(storage, '\n'))
		storage = ft_reading(fd, storage);
	if (!*storage)
		return (free(storage), storage = NULL, NULL);
	line = ft_get_line(storage);
	storage = ft_extract_rest(storage);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}*/
