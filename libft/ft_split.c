/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:20:59 by mramiro-          #+#    #+#             */
/*   Updated: 2023/11/16 15:44:54 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

int	cpalabas(const char *str, char c)
{
	int	n_palabras;
	int	flag;

	n_palabras = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			n_palabras++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (n_palabras);
}

int	cletras(char const *str, char c)
{
	int	i;

	i = 0;
	while (c != str[i] && str[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	int		size;
	int		i;
	int		n;

	if (!s)
		return (0);
	d = ft_calloc(sizeof(char *), cpalabas(s, c) + 1);
	i = 0;
	n = 0;
	if (!d)
		return (NULL);
	while (n < cpalabas(s, c))
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		size = cletras(s + i, c) + 1;
		d[n] = ft_calloc(sizeof(char), size);
		ft_strlcpy(d[n], (char *)s + i, size);
		i = size + i;
		n++;
	}
	return (d);
}
