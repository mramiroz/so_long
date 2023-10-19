/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:38:01 by mramiro-          #+#    #+#             */
/*   Updated: 2022/09/27 12:20:55 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	if (n == 0)
		return (0);
	n = n - 1;
	while (i < n && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
