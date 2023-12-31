/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:01:55 by aez-zoui          #+#    #+#             */
/*   Updated: 2023/11/18 21:45:58 by aez-zoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len_str;
	char	*strcp;
	int		i;

	i = 0;
	len_str = 0;
	while (str[len_str])
		len_str++;
	strcp = (char *)malloc(len_str + 1);
	if (!strcp)
		return (NULL);
	while (len_str > i)
	{
		strcp[i] = str[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}
