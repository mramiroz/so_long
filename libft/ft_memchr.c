/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramiro- <mramiro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:38:06 by mramiro-          #+#    #+#             */
/*   Updated: 2022/10/28 11:02:46 by mramiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str1;

	ch = (unsigned char)c;
	str1 = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (*str1 == ch)
			return (str1);
		str1++;
		i++;
	}
	return (0);
}
