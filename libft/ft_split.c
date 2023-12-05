/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:26 by svidal            #+#    #+#             */
/*   Updated: 2023/02/21 20:04:35 by svidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*str)
	{
		if (*str != c && word == 0)
		{
			word = 1;
			i++;
		}
		else if (*str == c)
			word = 0;
		str++;
	}
	return (i);
}

static char	*ft_allocate_words(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	size_t			j;
	int				index;
	char			**tab;

	if (s == NULL || c == '0')
		return (NULL);
	tab = ft_calloc(sizeof(char *), (ft_nb_words(s, c) + 1));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			tab[j++] = ft_allocate_words(s, index, i);
			index = -1;
		}
		i++;
	}
	return (tab);
}
