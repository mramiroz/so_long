/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrarmiro- <mramiro-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:29:49 by mrarmiro-         #+#    #+#             */
/*   Updated: 2022/09/30 09:29:49 by mrarmiro-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	trim(char const *c, char set)
{
	while (*c)
		if (*c++ == set)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;
	char	*s;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (trim(set, s1[start]) == 1)
		start++;
	while (start < end - 1 && trim(set, s1[end - 1]) == 1)
		end--;
	len = end - start;
	s = ft_calloc(sizeof(char), len + 1);
	if (!s)
		return (0);
	while (i < len)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}
