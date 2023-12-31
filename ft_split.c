/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:40:05 by aez-zoui          #+#    #+#             */
/*   Updated: 2023/11/18 13:00:51 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	f;
	int	count_word;
	int	i;

	count_word = 0;
	i = 0;
	f = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			f = 0;
		}
		else if (f == 0)
		{
			f = 1;
			count_word++;
		}
		i++;
	}
	return (count_word);
}

static char	*ft_create_word(char const *str, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	char	**ft_free(char **split, int i)
{
	while (--i)
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**dest;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	dest = (char **)malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!dest)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			dest[i++] = ft_create_word(str, c);
			if (dest[i - 1] == NULL)
				return (ft_free(dest, i));
			while (*str && *str != c)
				str++;
		}
	}
	dest[i] = NULL;
	return (dest);
}
